# Electrical Fault Detection Using Machine Learning on ESP32

This project demonstrates a machine learning approach to detecting electrical faults using a combination of TensorFlow, Python, and an ESP32 microcontroller. A neural network model is trained and converted to TensorFlow Lite format to be deployed on the ESP32 for real-time fault detection.

## Features

- **Machine Learning**: A binary classification model using TensorFlow to detect electrical faults from six electrical parameters: currents (Ia, Ib, Ic) and voltages (Va, Vb, Vc).
- **TensorFlow Lite Conversion**: Optimized model for deployment on resource-constrained devices like the ESP32.
- **Arduino Integration**: Generates a `.h` file to integrate the model into ESP32 using the Arduino IDE.

## Requirements

### Hardware:
- ESP32 Development Board
- Electrical input data source (e.g., simulated or real sensor data)

### Software:
- Python 3.x
- TensorFlow 2.x
- Scikit-learn
- Matplotlib
- Arduino IDE

## Project Files

- **`fault_detection_model.h5`**: The trained model in Keras format.
- **`fault_detection_model.tflite`**: The optimized TensorFlow Lite model.
- **`fault_detection_model_esp32.h`**: C header file for integrating the model with ESP32.
- **`detect_dataset.csv`**: The dataset used for training and testing the model.
- **`arduino_code.ino`**: Arduino sketch to run the model on ESP32.

## How It Works

### Model Training:

- The dataset is split into training and test sets.
- A neural network with 3 dense layers is trained to predict electrical faults.

### Model Conversion:

- The trained model is converted to TensorFlow Lite format.
- The TensorFlow Lite model is further converted to a C array header file for deployment.

### Deployment:

- The generated C array is included in an Arduino sketch.
- The ESP32 reads electrical parameters, runs the TensorFlow Lite model, and detects faults in real-time.

## Steps to Run

### Python (Model Training & Conversion):

1. Install required Python libraries:
   ```bash
   pip install tensorflow scikit-learn matplotlib pandas numpy

2. Run the Python script to train the model and generate .h and .tflite files:
   ```bash
   python fault_detection.py

   
### Arduino (ESP32 Deployment):

1. Install the Arduino TensorFlow Lite library.

2. Copy the fault_detection_model_esp32.h file into your Arduino sketch folder.

3. Upload the arduino_code.ino sketch to your ESP32.









