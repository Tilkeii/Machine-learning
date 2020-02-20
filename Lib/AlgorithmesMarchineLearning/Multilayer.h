#pragma once
#include <stdlib.h>
#include <math.h>
#include <Eigen>
#include "LinearModel.h"

extern "C" {
    __declspec(dllexport) double*** CreateMultiLayerModel(
        int count_layer,
        int* count_model,
        int max_len_model,
        int count_feature
    );
    __declspec(dllexport) void TrainMultiLayerRegressionModel();
    __declspec(dllexport) void TrainMultiLayerClassificationModel();
    __declspec(dllexport) double PredictMultiLayerRegressionModel(int count_neurones);
    __declspec(dllexport) double PredictMultiLayerClassificationModel();
}