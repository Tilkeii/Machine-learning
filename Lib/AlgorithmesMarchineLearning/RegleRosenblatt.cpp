#include "pch.h"
#include "RegleRosenblatt.h"

extern "C" {
    __declspec(dllexport) int GiveMe42FromC() {
        return 42;
    }

    __declspec(dllexport) int CreateModel() {
        return 0;
    }

    __declspec(dllexport) int TrainModel() {
        return 0;
    }

    __declspec(dllexport) int PredictModel() {
        return 0;
    }
}
