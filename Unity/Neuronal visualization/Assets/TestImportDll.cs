using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class TestImportDll : MonoBehaviour
{
    [DllImport("AlgorithmesMarchineLearning")]
    private static extern int GiveMe42FromC();

    [DllImport("AlgorithmesMarchineLearning")]
    private static extern IntPtr CreateLinearModel(int count_feature);

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log($"MyCDll : {GiveMe42FromC()}");

        double[] model = new double[3];

        Marshal.Copy(model, 0, CreateLinearModel(2), model.Length);

        foreach (var item in model)
        {
            Debug.Log($"Test : {item}");
        }

    }
}
