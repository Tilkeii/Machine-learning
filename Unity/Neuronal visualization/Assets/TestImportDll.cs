using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class TestImportDll : MonoBehaviour
{
    [DllImport("AlgorithmesMarchineLearning")]
    private static extern int GiveMe42FromC();
    
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log($"MyCDll : {GiveMe42FromC()}");
    }
}
