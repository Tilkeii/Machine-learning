#pragma once
#include <stdlib.h>
#include <math.h>
#include <Eigen>
#include "LinearModel.h"

extern "C" {
    __declspec(dllexport) double*** CreateMultiLayerModel(
        int count_layer,
        int* count_neurones,
        int count_feature
    );
    __declspec(dllexport) void TrainMultiLayerRegressionModel();
    __declspec(dllexport) void TrainMultiLayerClassificationModel();
    __declspec(dllexport) double PropagationMultiLayerRegressionModel(
        int count_layers,
        int* count_neurones,
        int count_weights
    );
    __declspec(dllexport) double PropagationMultiLayerClassificationModel(
        double*** network,
        int countlayers,
        int* count_neurones,
        int count_weights
    );
}