import numpy as np
from tensorflow import keras
from tensorflow.keras.datasets import mnist
from tensorflow.keras import models
from tensorflow.keras import layers
from tensorflow.keras.utils import to_categorical
import time
import numpy as np
import tensorflow as tf

# Set random seed to assert deterministic solution
np.random.seed(1234)
tf.random.set_seed(1234)

# Load the train and test dataset with their classes
(train, train_class), (test, test_class) = mnist.load_data()

# Preprocessing data
# Normalize data
train = train.astype("float32") / 255
test = test.astype("float32") / 255

# Reshape the data
train = np.expand_dims(train, -1)
test = np.expand_dims(test, -1)

# Encode the labels categorically
train_class = to_categorical(train_class,10)
test_class  = to_categorical(test_class,10)

# Define the model
neural_network = models.Sequential()

# Add different layers
neural_network.add(keras.Input(shape=(28, 28, 1)))
neural_network.add(layers.Conv2D(32, kernel_size=(3, 3), activation="relu"))
neural_network.add(layers.MaxPooling2D(pool_size=(2, 2)))
neural_network.add(layers.Conv2D(64, kernel_size=(3, 3), activation="relu"))
neural_network.add(layers.MaxPooling2D(pool_size=(2, 2)))
neural_network.add(layers.Flatten())
neural_network.add(layers.Dropout(0.5))
neural_network.add(layers.Dense(10, activation="softmax"))

# Start to count time
start_time = time.time()

# Compile the model
neural_network.compile(optimizer="adam", loss="categorical_crossentropy", metrics=["accuracy"])

# Train the model
neural_network.fit(train, train_class, epochs=15, batch_size=128)

# Evaluate the model
train_loss, train_accuracy = neural_network.evaluate(train, train_class, verbose=0) # Train data
test_loss, test_accuracy = neural_network.evaluate(test, test_class, verbose=0) # Test data

# Print time
print("--- %s seconds ---" % (time.time() - start_time))

# Print train results
print(f"Train Loss: {train_loss}")
print(f"Train Accuracy: {train_accuracy} %")

# Print test results
print(f"Test Loss: {test_loss}")
print(f"Test Accuracy: {test_accuracy} %")

