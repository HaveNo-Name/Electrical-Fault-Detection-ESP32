
#include <EloquentTinyML.h>
#include "fault_detection_model_esp32.h"  // Include the generated header file with the model

// Number of inputs and outputs
#define NUMBER_OF_INPUTS 6   // Number of features (Ia, Ib, Ic, Va, Vb, Vc)
#define NUMBER_OF_OUTPUTS 1  // Single output: Fault (1) or No Fault (0)
#define TENSOR_ARENA_SIZE 6*1024  // Adjust the tensor arena size based on model size

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);
   
    // Initialize the TinyML model
    ml.begin(fault_detection_model_esp32);
    Serial.println("Model loaded on ESP32.");
}

float fResult[NUMBER_OF_OUTPUTS] = {0};

void loop() {
    // Input data: Replace with real sensor readings or test data
    //float input_data_1[6] = {63.1268571f,	-36.79144884f,	-26.33540826f,	0.184998712f,	0.407249466f,	-0.592248178f};  // Row 1
    float input_data_1[6] = {63.04930979f,	-37.59981628f,	-25.44949351f,	0.193945373f,	0.400069434f,	-0.594014808f};
    float input_data_2[6] = {76.66768555f,	-42.84653552f,	49.86195756f,	0.371593631f,	-0.584645936f,	0.213052305f};  // Row 2

    // Prediction for row 1
    float fRes1 = ml.predict(input_data_1, fResult);
    Serial.print("Prediction Result for row 1: ");
    if (fResult[0] > 0.5) {
        Serial.println("Fault");
    } else {
        Serial.println("No Fault");
    }
    displayOutput(fResult);

    // Delay before next prediction
    delay(5000);  // Wait for 5 seconds before the next prediction

    // Prediction for row 2
    float fRes2 = ml.predict(input_data_2, fResult);
    Serial.print("Prediction Result for row 2: ");
    if (fResult[0] > 0.5) {
        Serial.println("Fault");
    } else {
        Serial.println("No Fault");
    }
    displayOutput(fResult);

    delay(5000);  // Wait for 5 seconds before the next prediction
}

void displayOutput(float *fResult) {
    Serial.print("Model Output: ");
    for (int i = 0; i < NUMBER_OF_OUTPUTS; i++) {
        Serial.print(fResult[i], 4);  // Print with 4 decimal places
        Serial.print(" ");
    }
    Serial.println();
}
