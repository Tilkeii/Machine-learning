#include "pch.h"
#include "LinearModel.h"
#include <stdio.h>
#include <iostream>

using namespace Eigen;

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

/**
	Premiere ligne de la matrix à 1
	[1, 6, 2, 4, 1, 3]
	=>
	1 1 6
	1 2 4
	1 1 3
*/
MatrixXd ArrayToMatrix(double* arr, int length, int count_feature) {

	MatrixXd mat = MatrixXd(length, count_feature + 1);

	for (int i = 0; i < length; i++)
	{
		mat(i, 0) = 1;
		for (int j = 1; j < count_feature + 1; j++)
		{
			mat(i, j) = arr[count_feature * i + (j - 1)];
		}
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

/*
	count_feature : correspond par exemple à l'age, le poid, etc.
*/
double* CreateLinearModel(int count_feature) {
	double* weight = new double[count_feature + 1];


	for (int i = 0; i < count_feature + 1; i++)
	{
		weight[i] = (2 * ((double)rand() / (double)RAND_MAX) - 1);
	}

	return weight;
}

double* TrainRegressionModel(
	double* model,
	double* trainingInputs,
	double* trainingExpectedOutputs,
	int trainingSphereLength,
	int count_feature
) {
	MatrixXd mat = ArrayToMatrix(trainingInputs, trainingSphereLength, count_feature);
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
double* TrainClassificationModel(
	double* model,
	double* trainingInputs,
	double* trainingExpectedOutputs,
	double pas_apprentissage,
	int count_iteration,
	int trainingSphereLength,
	int count_feature
) {
	for (int i = 0; i < count_iteration; i++)
	{
		int sample = rand() % trainingSphereLength;

		double* XK = trainingInputs + sample * count_feature;
		double error = pas_apprentissage * (trainingExpectedOutputs[sample] -
			PredictClassificationModel(
				model,
				XK,
				count_feature));

		if (error != 0) {
			model[0] += error;
			for (int t = 1; t < count_feature + 1; t++)
			{
				model[t] += XK[t - 1] * error;
			}
		}
	}

	return model;
}

double PredictRegressionModel(
	double* model,
	double* input,
	int count_feature
) {
	double res = model[0];
	for (int i = 1; i < count_feature + 1; i++)
	{
		res += model[i] * input[i - 1];
	}
	return res;
}


double PredictClassificationModel(
	double* model,
	double* input,
	int count_feature
) {
	auto rslt = PredictRegressionModel(model, input, count_feature);

	return rslt < 0 ? -1.0 : 1.0;
}

int FreeLinearModel(double* model) {
	return 0;
}

