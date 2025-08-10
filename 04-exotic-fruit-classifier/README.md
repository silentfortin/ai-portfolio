# 🍍 TropicTaste — Exotic Fruit Classification (KNN)

> Built for TropicTaste Inc. to automate and improve the accuracy of exotic fruit classification using machine learning.  
> A compact, reproducible project that trains a **K-Nearest Neighbors (KNN)** classifier on numeric fruit measurements and demonstrates preprocessing, model tuning, evaluation, and visualization.

---

## 📌 Project Overview

TropicTaste distributes exotic fruits and currently relies on manual classification by staff. Manual labeling is error-prone and slow — an automated classifier can speed up operations, reduce mistakes, and improve inventory and quality control.

This repository provides a complete pipeline to train, validate, and visualize a KNN model that predicts **fruit type** from numeric features such as weight, diameter, length, skin hardness and sweetness.

Key goals:
- Automate fruit type classification from numeric measurements.
- Achieve robust, generalizable predictions using cross-validation and hyperparameter tuning.
- Provide clear visualizations and easy-to-run notebooks/scripts for reproducibility.

---

## 🧱 Technologies & Concepts

- ✅ Python 3.10+
- ✅ Pandas for data handling
- ✅ NumPy for numeric computations
- ✅ scikit-learn for KNN, preprocessing and evaluation
- ✅ Matplotlib / Seaborn for plots
- ✅ Train/test split & Cross-validation
- ✅ Standardization / Scaling (e.g., StandardScaler)
- ✅ Hyperparameter tuning (GridSearchCV)
- ✅ Confusion matrix, accuracy, classification reports

---

## 🚀 Features

- 🔹 Load & preprocess the dataset (missing values handling, scaling/normalization).
- 🔹 Exploratory Data Analysis (EDA) with summary stats and visualizations.
- 🔹 Train KNN classifier and search for best `k` / distance metric using cross-validation.
- 🔹 Evaluate performance: cross-validated accuracy, confusion matrix, classification report.
- 🔹 Visualize results: accuracy vs k, confusion matrix heatmap, 2D feature projections (PCA) with class separation.
- 🔹 Export model (optional) for integration into downstream systems.

---

## 📂 Project Structure (suggested)

//


---

## 📥 Dataset

Download the dataset:

**URL:** https://proai-datasets.s3.eu-west-3.amazonaws.com/fruits.csv

**Variables:**

| Variable           | Description                          | Type       |
|--------------------|------------------------------------|------------|
| `Fruit`            | Target: the fruit type (categorical) | Categorical |
| `Weight (g)`       | Weight of the fruit in grams        | Continuous |
| `Mean diameter (mm)` | Average diameter in millimeters     | Continuous |
| `Mean length (mm)` | Average length in millimeters       | Continuous |
| `Skin hardness (1-10)` | Hardness of the skin on a 1–10 scale | Continuous |
| `Sweetness (1-10)` | Sweetness level on a 1–10 scale     | Continuous |

---

