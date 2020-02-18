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

    __declspec(dllexport) int PredictLinearModel(double *model, double input[], int count_feature) {
        return 0;
    }

    __declspec(dllexport) int FreeLinearModel(double *model) {
        return 0;
    }
}
