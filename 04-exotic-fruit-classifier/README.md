# 🍍 TropicTaste — Exotic Fruit Classification (KNN)

> Machine learning solution for TropicTaste Inc. to automate and improve the accuracy of exotic fruit classification.  
> A complete, reproducible pipeline that trains a **K-Nearest Neighbors (KNN)** classifier on numeric fruit measurements, including preprocessing, hyperparameter tuning, evaluation, and visualization.

---

## 📌 Project Overview

TropicTaste Inc., a leading distributor of exotic fruits, currently classifies fruit manually — a process that is time-consuming, resource-intensive, and prone to human error.  
An automated classifier can speed up operations, reduce mistakes, optimize inventory, and maintain high quality standards.

This repository implements a **full machine learning workflow** to predict **fruit type** from numeric features such as weight, dimensions, skin hardness, and sweetness, using the KNN algorithm.

**Key objectives:**
- Automate fruit classification from physical measurements.
- Ensure robust, generalizable predictions via cross-validation and hyperparameter optimization.
- Provide clear visual insights and an easy-to-run, reproducible workflow.

---

## 🧱 Technologies & Concepts

- ✅ Python 3.10+
- ✅ **Pandas** — data handling  
- ✅ **NumPy** — numeric computations  
- ✅ **scikit-learn** — KNN, preprocessing, evaluation, model selection  
- ✅ **Matplotlib / Seaborn** — data visualization  
- ✅ Train/test split & **Stratified k-fold cross-validation**  
- ✅ Feature scaling with **MinMaxScaler**  
- ✅ Feature transformation (log) for skewed variables  
- ✅ Hyperparameter tuning with `GridSearchCV`  
- ✅ Performance metrics: accuracy, classification report, confusion matrix  
- ✅ Learning curves & accuracy-vs-k analysis

---

## 🚀 Features

- 🔹 Load and inspect dataset directly from URL.  
- 🔹 Exploratory Data Analysis (EDA) — correlation heatmap, distribution plots, boxplots per class.  
- 🔹 Preprocessing:
  - Log transformation of skewed features (Weight)
  - MinMax scaling of numerical features
  - Label encoding of target
- 🔹 KNN model training inside a **Pipeline** with preprocessing steps.  
- 🔹 Hyperparameter search over:
  - Number of neighbors (`n_neighbors`)
  - Distance metric (`euclidean`, `manhattan`, `minkowski`)
  - Weighting scheme (`uniform`, `distance`)
- 🔹 Model evaluation with train/test split, cross-validation, classification reports, and error rates.  
- 🔹 Visualization of:
  - Learning curves
  - Confusion matrix
  - Accuracy vs. k plots

---

## 📂 Project Structure

04-exotic-fruit-classifier/
│
├── README.md
│
├── fruits_classification.ipynb

---

## 📥 Dataset

**URL:** https://proai-datasets.s3.eu-west-3.amazonaws.com/fruits.csv

**Variables:**

| Variable               | Description                               | Type        |
|------------------------|-------------------------------------------|-------------|
| `Frutto`               | Target: fruit type                        | Categorical |
| `Peso (g)`             | Fruit weight in grams                     | Continuous  |
| `Diametro medio (mm)`  | Average diameter in millimeters           | Continuous  |
| `Lunghezza media (mm)` | Average length in millimeters             | Continuous  |
| `Durezza buccia (1-10)`| Skin hardness on a 1–10 scale             | Continuous  |
| `Dolcezza (1-10)`      | Sweetness level on a 1–10 scale           | Continuous  |

---

## 📊 Results Summary

- **Best parameters:** `n_neighbors=55`, `metric='manhattan'`, `weights='uniform'`  
- **Cross-validation accuracy:** 93.88%  
- **Test set accuracy:** 86.67%  
- Strong classification performance with low variance; misclassifications mainly occur between oranges and kiwis.  

---


