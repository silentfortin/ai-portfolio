# 🏠 RealEstateAI Solutions

### Predictive Modeling for Real Estate Pricing

**Developed as part of the AI Engineering Master – Week 2**

---

## 📌 Overview

This project focuses on building a predictive model to estimate real estate prices using **linear regression techniques with regularization**. The goal is to improve generalization, mitigate overfitting, and produce reliable pricing predictions on housing data.

Three regularized linear models are implemented and compared:

* **Ridge Regression**
* **Lasso Regression**
* **Elastic Net Regression**

The performance of these models is assessed using cross-validation, error metrics, and model complexity (sparsity).

---

## 🎯 Objectives

* Load and preprocess a housing dataset
* Handle missing values and categorical variables appropriately
* Normalize features for regularized models
* Train Ridge, Lasso, and Elastic Net regression models
* Perform model selection using `GridSearchCV`
* Evaluate performance via:

  * MSE, RMSE, and R²
  * Residual analysis
  * Model complexity (number of non-zero coefficients)
* Visualize and interpret results

---

## 📁 Project Structure

```
├── RealEstateAI_PricePrediction.ipynb    # Main notebook with full analysis
├── README.md                             # Project description 
```

---

## ⚙️ Technologies & Libraries

* Python 3.x
* NumPy, Pandas
* Scikit-learn
* Matplotlib / Seaborn

---

## 📊 Results Summary

* All three models perform similarly on the test set, with **Elastic Net** slightly outperforming others in terms of test MSE and R².
* **No significant feature elimination** was observed from Lasso, likely due to low alpha values.
* **Regularization improved generalization**, with reduced overfitting compared to the unregularized model.
* A thorough **residual analysis** revealed the presence of **heteroscedasticity**, suggesting potential improvements using non-linear models or transformations.

---

## 📌 Example Output

| Model       | Test RMSE    | Test R² | Non-Zero Coefficients |
| ----------- | ------------ | ------- | --------------------- |
| Ridge       | 1,226,043.82 | 0.651   | 12 / 12               |
| Lasso       | 1,228,297.71 | 0.650   | 12 / 12               |
| Elastic Net | 1,224,420.35 | 0.652   | 12 / 12               |

---

## ✅ Conclusions

* Linear models with regularization are effective for housing price prediction in this dataset.
* Lasso and Elastic Net did not produce sparsity due to limited regularization strength.
* Further improvements may require:

  * Feature engineering
  * Non-linear models (e.g., tree-based methods)
  * Transformation to address heteroscedasticity

---
