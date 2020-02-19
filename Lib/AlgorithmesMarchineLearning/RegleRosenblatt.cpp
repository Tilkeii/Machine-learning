#include "pch.h"
#include "RegleRosenblatt.h"
#include <stdio.h>
#include <iostream>


using namespace Eigen;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

/**
    Premiere ligne de la matrix � 1
    [1, 6, 2, 4, 1, 3] 
    =>
    1 1 6 
    1 2 4 
    1 1 3
*/
MatrixXd ArrayToMatrix(double* arr, int length) {

    MatrixXd mat = MatrixXd(length / 2, 3);

    for (int i = 0; i < length/2; i++)
    {
        mat(i, 0) = 1;
        mat(i, 1) = arr[2*i];
        mat(i, 2) = arr[2*i + 1];
        std::cout << mat(i, 0) << mat(i, 1) << mat(i, 2);
    }

    return mat;
}

double* MatrixToArray(MatrixXd mat) {

    double* arr = new double[mat.size() * mat.row(0).size()];
    int cmpt = 0;

    for (size_t i = 0; i < (int)mat.size(); i++)
    {
        for (size_t t = 0; t < (int)mat.row(i).size(); t++)
        {
            arr[cmpt] = mat(i, t);
            cmpt++;
        }
    }

    return arr;
}

extern "C" {
    /*
        count_feature : correspond par exemple � l'age, le poid, etc.
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

        for (int i = 0; i < trainingSphereLength; i++)
        {
            Y(i) = trainingExpectedOutputs[i];
        }

        MatrixXd W = ((matT * mat).inverse() * matT) * Y;

        for (int i = 0; i < W.rows(); i++)
        {
            model[i] = W(i, 0);
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
        int trainingSphereLength
    ) {
        MatrixXd matInput = ArrayToMatrix(trainingInputs, trainingSphereLength * 2);

        for (size_t i = 0; i < count_iteration; i++)
        {   
            int sample = rand() % trainingSphereLength;

            double* XK = trainingInputs + sample * 2;
            double error = pas_apprentissage * (trainingExpectedOutputs[sample] -
                PredictClassificationModel(
                    model,
                    XK));
            
            model[0] += error;
            for (size_t t = 1; t < 3; t++)
            {
                model[t] += XK[t] * error;
            }
        }

        return model;
    }

    __declspec(dllexport) double PredictRegressionModel(double* model, double* input) {
        return model[0] + model[1] * input[0] + model[2] * input[1];
    }


    __declspec(dllexport) double PredictClassificationModel(
        double *model, 
        double *input
    ) {
        return sgn(PredictRegressionModel(model, input));
    }

    __declspec(dllexport) int FreeLinearModel(double *model) {
        return 0;
    }
}
