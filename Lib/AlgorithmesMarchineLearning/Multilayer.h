#pragma once
#include <stdlib.h>
#include <math.h>
#include <Eigen>

extern "C" {
    __declspec(dllexport) double*** CreateMultiLayerModel();
    __declspec(dllexport) void TrainMultiLayerRegressionModel();
    __declspec(dllexport) void TrainMultiLayerClassificationModel();
    __declspec(dllexport) void PredictMultiLayerClassificationModel();
}