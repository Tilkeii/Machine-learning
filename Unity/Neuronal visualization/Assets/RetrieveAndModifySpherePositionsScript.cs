﻿using System;
using System.Runtime.InteropServices;
using UnityEngine;
using Random = UnityEngine.Random;

public class RetrieveAndModifySpherePositionsScript : MonoBehaviour
{
    public Transform[] trainingSpheres;

    public Transform[] testSpheres;


    private double[] trainingInputs;

    private double[] trainingExpectedOutputs;

    private IntPtr modelPtr;

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr CreateLinearModel(int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr PredictClassificationModel(
        IntPtr model,
        double[] input,
        int len_input,
        int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern double PredictRegressionModel(
        IntPtr model,
        double[] input,
        int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr TrainRegressionModel(
        IntPtr model,
        double[] trainingInputs,
        double[] trainingExpectedOutputs,
        int trainingSphereLength,
        int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr TrainClassificationModel(
        IntPtr model,
        double[] trainingInputs,
        double[] trainingExpectedOutputs,
        double pas_apprentissage,
        int count_iteration,
        int trainingSphereLength,
        int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern double PredictClassificationModel(
        IntPtr model,
        double[] input,
        int count_feature
    );


    public void ReInitialize()
    {
        for (var i = 0; i < testSpheres.Length; i++)
        {
            testSpheres[i].position = new Vector3(
                testSpheres[i].position.x,
                0f,
                testSpheres[i].position.z);
        }
    }
    
    public void CreateModel()
    {
        //model = CreateLinearModel(2, 1);
        Debug.Log($"/****************************/");
        Debug.Log($"CREATE LINEAR MODEL");

        //double[] model = new double[3];

        modelPtr = CreateLinearModel(2);

        //Marshal.Copy(modelPtr, model, 0, model.Length);

        /*foreach (var item in model)
        {
            Debug.Log($"Test : {item}");
        }*/

        Debug.Log($"/****************************/");
    }

    public void Train()
    {
/*        trainingInputs = new double[trainingSpheres.Length * 2];
        trainingExpectedOutputs = new double[trainingSpheres.Length];

        for (var i = 0; i < trainingSpheres.Length; i++)
        {
            trainingInputs[2 * i] = trainingSpheres[i].position.x;
            trainingInputs[2 * i + 1] = trainingSpheres[i].position.z;
            trainingExpectedOutputs[i] = trainingSpheres[i].position.y;
        }*/
        
        // TrainLinearModelRosenblatt(model, trainingInputs, 2, trainingSpheres.Length, trainingExpectedOutputs, 1, 0.01, 1000)
    }

    public void TrainRegressionModel()
    {
        Debug.Log($"/****************************/");
        Debug.Log($"TRAIN REGRESSION MODEL");

        trainingInputs = new double[trainingSpheres.Length * 2];
        trainingExpectedOutputs = new double[trainingSpheres.Length];


        for (var i = 0; i < trainingSpheres.Length; i++)
        {
            trainingInputs[2 * i] = trainingSpheres[i].position.x;
            trainingInputs[2 * i + 1] = trainingSpheres[i].position.z;
            trainingExpectedOutputs[i] = trainingSpheres[i].position.y;
        }

        TrainRegressionModel(modelPtr, trainingInputs, trainingExpectedOutputs, trainingSpheres.Length, 2);

        Debug.Log($"/****************************/");
    }

    public void TrainClassificationModel()
    {
        Debug.Log($"/****************************/");
        Debug.Log($"TRAIN REGRESSION MODEL");

        trainingInputs = new double[trainingSpheres.Length * 2];
        trainingExpectedOutputs = new double[trainingSpheres.Length];


        for (var i = 0; i < trainingSpheres.Length; i++)
        {
            trainingInputs[2 * i] = trainingSpheres[i].position.x;
            trainingInputs[2 * i + 1] = trainingSpheres[i].position.z;
            trainingExpectedOutputs[i] = trainingSpheres[i].position.y;
        }

        TrainClassificationModel(modelPtr, trainingInputs, trainingExpectedOutputs, 0.01, 10000, trainingSpheres.Length, 2);

        Debug.Log($"/****************************/");
    }

    public void PredictRegression()
    {
        for (var i = 0; i < testSpheres.Length; i++)
        {
            var input = new double[] {testSpheres[i].position.x, testSpheres[i].position.z};

            //var predictedY = PredictXXXLinearModel(model, input, 2)
            double predictedY = PredictRegressionModel(modelPtr, input, 2);

            //var predictedY = Random.Range(-5, 5);
            testSpheres[i].position = new Vector3(
                testSpheres[i].position.x,
                (float) predictedY,
                testSpheres[i].position.z);
        }
    }

    public void PredictClassification()
    {
        for (var i = 0; i < testSpheres.Length; i++)
        {
            var input = new double[] { testSpheres[i].position.x, testSpheres[i].position.z };

            //var predictedY = PredictXXXLinearModel(model, input, 2)
            double predictedY = PredictClassificationModel(modelPtr, input, 2);

            //var predictedY = Random.Range(-5, 5);
            testSpheres[i].position = new Vector3(
                testSpheres[i].position.x,
                (float)predictedY,
                testSpheres[i].position.z);
        }
    }

    public void ReleaseModel()
    {
        // FreeLinearModel(model);
    }
}