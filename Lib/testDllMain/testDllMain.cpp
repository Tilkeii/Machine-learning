// testDllMain.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "../AlgorithmesMarchineLearning/LinearModel.h"
#include "../AlgorithmesMarchineLearning/Multilayer.h"

int main()
{
    // LINEAR
    //double* model;
    //model = CreateLinearModel(2);
    //for (int i = 0; i < 3; i++)
    //{
    //    std::cout << model[i];
    //}
    //
    //double trainingInputs[] = { 0, 1, 2, 3, 4, 5 };
    //int trainingSphereLength = 3;
    //double trainingExpectedOutput[] = {1, 1, -1};
    ////model = TrainRegressionModel(model, trainingInputs, trainingSphereLength, trainingExpectedOutput);
    //model = TrainClassificationModel(model, trainingInputs, trainingExpectedOutput, 0.01, 1000, trainingSphereLength);

    //std::cout << "model : " << model;

    // PCM

    double trainingInputs[] = { 0, 1, 2, 3, 4, 5 };
    int count_neurone[] = {3, 3, 1};
    double** network = CreateMultiLayerModel(3, count_neurone, 2, trainingInputs);

    for (int layer = 0; layer < 3; layer++)
    {
        for (int neurone = 0; neurone < count_neurone[layer]; neurone++)
        {
            std::cout
                << "Layer " << layer
                << " ; Neurone " << neurone
                << " ; value " << network[layer][neurone]
                << "\n";
        }
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
