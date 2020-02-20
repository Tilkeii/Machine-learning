#include "pch.h"
#include "Multilayer.h"

double*** CreateMultiLayerModel(int count_layer, int* count_model, int max_len_model, int count_feature)
{
	// Initialisation mémoire du network
	double*** layers = new double** [count_layer];

	for (int i = 0; i < count_layer; i++) // Layers
	{
		layers[i] = new double* [count_model[i]]; // Initialisation mémoire de la couche "i"
		for (int j = 0; j < count_model[i]; j++) // Models = neuronnes
		{
			layers[i][j] = new double[count_feature + 1]; // Initialisation mémoire du model "i, j" 
			double* weights = CreateLinearModel(count_feature); // Creation d'un model w1, w2, w3
			layers[i][j] = weights; // Attribution du model
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

double PredictMultiLayerRegressionModel(int count_neurones)
{

	for (int neurone = 0; neurone < count_neurones; neurone++)
	{
		//for (int  = 0; j < length; j++)
		//{

		//}
	}

	return NULL;
}

double PredictMultiLayerClassificationModel()
{
	return NULL;
}

