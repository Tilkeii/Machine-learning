#include "pch.h"
#include "Multilayer.h"

double*** CreateMultiLayerModel(
	int count_layer,
	int* count_neurones, 
	int count_feature)
{
	// Initialisation mémoire du network
	double*** network = new double** [count_layer];

	// Creation input layer
	network[0] = new double* [count_neurones[0]];
	for (int input_neurone = 0; input_neurone < count_feature + 1; input_neurone++)
	{
		network[0][input_neurone] = new double [count_feature];
		network[0][input_neurone] = CreateLinearModel(count_feature);
	}

	// Creation hidden layer
	for (int layer = 1; layer < count_layer; layer++) // Layers
	{
		network[layer] = new double* [count_neurones[layer]]; // Initialisation mémoire de la couche "i"
		for (int neurone = 0; neurone < count_neurones[layer]; neurone++) // Models = neuronnes
		{
			network[layer][neurone] = new double[count_neurones[layer - 1]]; // Initialisation mémoire du model "i, j" 
			double* weights = CreateLinearModel(count_neurones[layer - 1]); // Creation d'un model w1, w2, w3
			network[layer][neurone] = weights; // Attribution du model
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
	return NULL;
}

double PredictMultiLayerClassificationModel(
	double*** network,
	int countlayers,
	int* count_neurones,
	int count_weights,
	double* inputs)
{



	return NULL;
}

