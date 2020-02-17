using System;
using UnityEngine;

public class TestTest : MonoBehaviour
{

    public Transform[] trainingSpheres;

    public Transform[] testSpheres;

    private double[] trainingInputs;

    private double[] trainingExpectedOutputs;

    private IntPtr model;

    public void Initialize() {

    }

    public void CreateModel() {
        // model = createModel();
    }

    public void Train() {
        trainingInputs = new double[trainingSpheres.Length * 2];
        trainingExpectedOutputs = new double[trainingSpheres.Length];

        for (int i = 0; i < trainingSpheres.Length; i++)
        {
            trainingInputs[2 * i] = trainingSpheres[i].position.x;
            trainingInputs[2 * i + 1] = trainingSpheres[i].position.z;
            trainingExpectedOutputs[i] = trainingSpheres[i].position.y;
        }

        // trainLinearModelRosenBlatt(model, trainingInputs, 2, trainingSpheres.Length, trainingExpectedOutputs.Length)
    }

    public void PredictOnTestSpheres() {
        for (int i = 0; i < testSpheres.Length; i++)
        {
            var input = new double[] {testSpheres[i].position.x, testSpheres[i].position.z};
            var predictedY = UnityEngine.Random.Range(-5, 5);

        }
    }

    public void PredictModel() {

    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
