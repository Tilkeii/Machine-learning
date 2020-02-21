#include "pch.h"
#include "Multilayer.h"

double** CreateMultiLayerModel(
	int count_layer,
	int* count_neurones, 
	int count_feature,
	double* inputs)
{
	// Initialisation mémoire du network
	double** network = new double* [count_layer];

	for (int layer = 0; layer < count_layer; layer++) // Layers
	{
		network[layer] = new double [count_neurones[layer]]; // Initialisation mémoire de la couche "i"
		for (int neurone = 0; neurone < count_neurones[layer]; neurone++) // Models = neuronnes
		{
			double* weights = CreateLinearModel(count_feature); // Creation d'un model w1, w2, w3
			network[layer][neurone] = PredictClassificationModel(weights, inputs, count_feature); // Valeur du neurone
		}
	}

	return network;
}

void TrainMultiLayerRegressionModel()
{
}

void TrainMultiLayerClassificationModel()
{
}

double PredictMultiLayerRegressionModel(
	int countlayers,
	int* count_neurones,
	int count_weights)
{

	for (int layer = 1; layer < countlayers; layer++)
	{
		for (int neurone = 0; neurone < count_neurones[layer]; neurone++)
		{
			for (int weight = 0; weight < count_weights; weight++)
			{

			}
		}
	}

	return NULL;
}

double PredictMultiLayerClassificationModel(
	double** network,
	int countlayers,
	int* count_neurones,
	int count_weights)
{
	for (int layer = 1; layer < countlayers; layer++)
	{
		for (int neurone = 0; neurone < count_neurones[layer]; neurone++)
		{
			double res;

			for (int prev_layer_neurone = 0; prev_layer_neurone < count_neurones[layer - 1]; prev_layer_neurone++)
			{

				//double* model = network[layer][prev_layer_neurone];
				//PredictClassificationModel(model, );

			}

			//tanh

		}
	}

	return NULL;

	return NULL;
}

