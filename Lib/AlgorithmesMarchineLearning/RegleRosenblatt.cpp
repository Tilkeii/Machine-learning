#include "pch.h"
#include "RegleRosenblatt.h"


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

extern "C" {


    __declspec(dllexport) int GiveMe42FromC() {
        return 42;
    }

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

    __declspec(dllexport) int TrainLinearModel(
        double *model, double trainingInputs[],
        int count_feature, int trainingSphereLength,
        double trainingExpectedOutputs[],
        int biais,
        float pas_apprentissage,
        int count_iteration
    ) {
        return 0;
    }

    /**
        count_input : total input
    */
    __declspec(dllexport) double* PredictRegressionModel(double* model, double* input, int len_input, int count_feature) {

        double *resultat = new double[len_input / 2];
        int cmpt = 0;

        for (size_t i = 0; i < len_input - 1; i+=2)
        {
            resultat[cmpt] = model[0] + model[1] * input[i] + model[2] * input[i + 1];
            cmpt++;
        }
        return resultat;
    }

    __declspec(dllexport) double* PredictLinearModel(
        double *model, 
        double *input,
        int len_input,
        int count_feature
    ) {
        double* resultat = new double[len_input];
        
        double* regression = PredictRegressionModel(model, input, len_input, count_feature);
        for (size_t i = 0; i < len_input / 2; i++)
        {
            resultat[i] = sgn(regression[i]);
        }

        return resultat;
    }

    __declspec(dllexport) int FreeLinearModel(double *model) {
        return 0;
    }
}
