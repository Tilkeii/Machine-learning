using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class TestImportDll : MonoBehaviour
{
    public Transform[] spheres;

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern int GiveMe42FromC();

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr CreateLinearModel(int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr PredictLinearModel(
        IntPtr model,
        double[] input,
        int len_input,
        int count_feature);

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr PredictRegressionModel(
        IntPtr model,
        double[] input,
        int len_input,
        int count_feature);

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log($"MyCDll : {GiveMe42FromC()}");

        Debug.Log($"CREATE LINEAR MODEL");

        double[] model = new double[3];

        IntPtr modelPtr = CreateLinearModel(2);

        Marshal.Copy(modelPtr, model, 0, model.Length);

        foreach (var item in model)
        {
            Debug.Log($"Test : {item}");
        }

        Debug.Log($"/****************************/");
        Debug.Log($"PREDICT REGRESSION MODEL");

        double[] predictRegression = new double[3];

        double[] input = new double[spheres.Length * 2];
        for (int i = 0; i < spheres.Length * 2; i+=2)
        {
            input[i] = spheres[i].position.x;
            input[i + 1] = spheres[i].position.z;
        }

        IntPtr predictRegressionPtr = PredictRegressionModel(modelPtr, input, input.Length, 2);

        Marshal.Copy(predictRegressionPtr, predictRegression, 0, predictRegression.Length);

        foreach (var item in predictRegression)
        {
            Debug.Log($"Predict Regression : {item}");
        }

        Debug.Log($"/****************************/");
        Debug.Log($"PREDICT LINEAR MODEL");



    }
}
