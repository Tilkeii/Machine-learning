using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class TestImportDll : MonoBehaviour
{

    // Start is called before the first frame update
    void Start()
    {

/*        
        Debug.Log($"PREDICT REGRESSION MODEL");

        double[] predictRegression = new double[3];

        for (int i = 0; i < input.Length - 1; i+=2)
        {
            input[i] = testSpheres[i/2].position.x;
            input[i + 1] = testSpheres[i/2].position.z;
        }

        IntPtr predictRegressionPtr = PredictRegressionModel(modelPtr, input, input.Length, 2);

        Marshal.Copy(predictRegressionPtr, predictRegression, 0, predictRegression.Length);

        foreach (var item in predictRegression)
        {
            Debug.Log($"Predict Regression : {item}");
        }*/

    }
}
