#include "pch.h"
#include "RegleRosenblatt.h"

using namespace Eigen;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

/**
    Premiere ligne de la matrix à 1
    [1, 6, 2, 4, 1, 3] 
    =>
    1 1 6 
    1 2 4 
    1 1 3
*/
MatrixXd ArrayToMatrix(double* arr, int len) {

    MatrixXd mat = MatrixXd(len / 2, 3);

    for (size_t i = 0; i < len - 1; i+=2)
    {
        mat << Vector3d(1, arr[i], arr[i + 1]);
    }

    return mat;
}

double* sliceDoubleArray(int start, int end, double* arr, int len) {

    int cmpt = 0;
    double* res = new double[end - start + 1];
    for (size_t i = 0; i < len; i++)
    {
        if (i >= start) {
            res[cmpt] = arr[i];
            cmpt++;
        }

        if (i > end) {
            return res;
        }
    }
    return NULL;
}

double* MatrixToArray(MatrixXd mat) {

    double* arr = new double[mat.size() * mat.row(0).size()];
    int cmpt = 0;

    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t t = 0; t < mat.row(i).size(); t++)
        {
            arr[cmpt] = mat(i, t);
            cmpt++;
        }
    }

    return arr;
}

extern "C" {
    /*
        count_feature : correspond par exemple à l'age, le poid, etc.
    */
    __declspec(dllexport) double* CreateLinearModel(int count_feature) {
        double* weight = new double[count_feature + 1];


        for (size_t i = 0; i < count_feature + 1; i++)
        {
            weight[i] = (2 * ((double)rand() / (double)RAND_MAX) -1);
        }

        return weight;
    }

    __declspec(dllexport) double* TrainRegressionModel(
        double* model, 
        double* trainingInputs, 
        int trainingSphereLength,
        double* trainingExpectedOutputs
    ) { 
        MatrixXd mat = ArrayToMatrix(trainingInputs, trainingSphereLength * 2);
        MatrixXd matT = mat.transpose();
        VectorXd Y(trainingSphereLength);

        for (size_t i = 0; i < trainingSphereLength; i++)
        {
            Y << trainingExpectedOutputs[i];
        }

        auto W = ((matT * mat).inverse() * matT)* Y;
        int cmpt = 0;

        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t t = 0; t < mat.row(i).size(); t++)
            {
                model[cmpt] = W(i, t);
                cmpt++;
            }
        }

        return model;
    }

    /**
        Rosenblatt
    */
    __declspec(dllexport) double* TrainClassificationModel(
        double* model, 
        double* trainingInputs,
        double* trainingExpectedOutputs,
        double pas_apprentissage,
        double count_iteration,
        double old_weight,
        int trainingSphereLength
    ) {

        double new_weight = old_weight;
        MatrixXd matInput = ArrayToMatrix(trainingInputs, trainingSphereLength * 2);

        for (size_t i = 0; i < count_iteration; i++)
        {
            for (size_t t = 0; t < trainingSphereLength; t++)
            {

            }

            int sample = rand() % trainingSphereLength;
            /* trainingInputs + sample * 2 => on decalle par rapport a l'adresse */
            /*new_weight = new_weight + pas_apprentissage * (trainingExpectedOutputs[sample] -
                PredictClassificationModel(model, trainingInputs + sample * 2, trainingSphereLength * 2)) * matInput.row(sample);*/
            /*new_weight = new_weight + pas_apprentissage * (trainingExpectedOutputs[sample] -
                PredictClassificationModel(
                    model,
                    sliceDoubleArray(sample * 2, sample * 2 + 1, trainingInputs, trainingSphereLength * 2),
                    trainingSphereLength * 2)) *
                matInput.row(sample);*/
        }

        return model;
    }

    /*
        input => [x, z];
    */
    __declspec(dllexport) double PredictRegressionModel(double* model, double* input) {
        return model[0] + model[1] * input[0] + model[2] * input[1];
    }

    /*
        input => [x, z];
    */
    __declspec(dllexport) double PredictClassificationModel(
        double *model, 
        double *input,
        int len_input
    ) {

        return sgn(PredictRegressionModel(model, input));
    }

    __declspec(dllexport) int FreeLinearModel(double *model) {
        return 0;
    }
}
