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
        
        for (size_t i = 0; i < count_feature + 1; i++)
        {
            weight[i] = (double) (rand() % 2 - 1);
        }

        return weight;
    }

    __declspec(dllexport) int TrainLinearModel() {
        return 0;
    }

    __declspec(dllexport) int PredictLinearModel() {
        return 0;
    }

    __declspec(dllexport) int FreeLinearModel() {
        return 0;
    }
}
