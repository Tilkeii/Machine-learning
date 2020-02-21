#include "pch.h"
#include "Multilayer.h"

double*** CreateMultiLayerModel(
	int count_layer,
	int* count_neurones, 
	int count_feature)
{
	// Initialisation mémoire du network
	double*** layers = new double** [count_layer];

	for (int layer = 0; layer < count_layer; layer++) // Layers
	{
		layers[layer] = new double* [count_neurones[layer]]; // Initialisation mémoire de la couche "i"
		for (int neurone = 0; neurone < count_neurones[layer]; neurone++) // Models = neuronnes
		{
			layers[layer][neurone] = new double[count_feature + 1]; // Initialisation mémoire du model "i, j" 
			double* weights = CreateLinearModel(count_feature); // Creation d'un model w1, w2, w3
			layers[layer][neurone] = weights; // Attribution du model
		}
	}

	return layers;
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
	double*** network,
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


			}

			//tanh

		}
	}

	return NULL;

	return NULL;
}

