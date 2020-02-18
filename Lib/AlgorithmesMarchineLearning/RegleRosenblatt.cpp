#include "pch.h"
#include "RegleRosenblatt.h"


extern "C" {
    __declspec(dllexport) int GiveMe42FromC() {
        return 42;
    }

    /*
        count_feature : correspond par exemple à l'age, le poid, etc.
    */
    __declspec(dllexport) double* CreateLinearModel(int count_feature) {
        double* weight = new double[count_feature + 1];

        static int table[] = { -1, 1 };

        for (size_t i = 0; i < count_feature + 1; i++)
        {
            weight[i] = table[rand() % 2];
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
    __declspec(dllexport) double* PredictRegressionModel(double* model, double* input, int count_input, int count_feature, int biais) {

        double *resultat = new double[count_input];
        int cmpt = 0;

        for (size_t i = 0; i < count_input - 1; i+=2)
        {
            resultat[cmpt] = biais + model[1] * input[i] + model[2] * input[i + 1];
            cmpt++;
        }
        return resultat;
    }

    __declspec(dllexport) double* PredictLinearModel(
        double *model, 
        double *input,
        int count_input,
        int count_feature,
        int biais
    ) {
        double* resultat = new double[count_input];
        
        double* regression = PredictRegressionModel(model, input, count_input, count_feature, biais);
        for (size_t i = 0; i < count_input; i++)
        {
            resultat[i] = signbit(regression[i]);
        }

        return resultat;
    }

    __declspec(dllexport) int FreeLinearModel(double *model) {
        return 0;
    }
}
