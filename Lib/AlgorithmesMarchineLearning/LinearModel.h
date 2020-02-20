#pragma once
#include <stdlib.h>
#include <math.h>
#include <Eigen>

using namespace Eigen;

MatrixXd ArrayToMatrix(double* arr, int len);
double* MatrixToArray(MatrixXd mat);

extern "C" {
    __declspec(dllexport) double* CreateLinearModel(int count_feature);
    __declspec(dllexport) double* TrainRegressionModel(
        double* model,
        double* trainingInputs,
        int trainingSphereLength,
        double* trainingExpectedOutputs
    );
    __declspec(dllexport) double* TrainClassificationModel(
        double* model,
        double* trainingInputs,
        double* trainingExpectedOutputs,
        double pas_apprentissage,
        int count_iteration,
        int trainingSphereLength
    );
    __declspec(dllexport) double PredictRegressionModel(double* model, double* input);
    __declspec(dllexport) int FreeLinearModel(double* model);
    __declspec(dllexport) double PredictClassificationModel(
        double* model,
        double* input
    );
}