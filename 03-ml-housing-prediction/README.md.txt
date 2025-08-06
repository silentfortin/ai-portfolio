# RealEstateAI Solutions

### Predictive Modeling for Real Estate Pricing  
**Developed as part of the AI Engineering Master – Week 2**

---

## Overview

This project focuses on building a predictive model to estimate real estate prices using **linear regression techniques with regularization**. The goal is to improve generalization, mitigate overfitting, and produce reliable pricing predictions on housing data.

Three regularized linear models are implemented and compared:

- Ridge Regression  
- Lasso Regression  
- Elastic Net Regression

The performance of these models is assessed using cross-validation, error metrics, and model complexity (sparsity).

---

## Objectives

- Load and preprocess a housing dataset  
- Handle missing values and categorical variables appropriately  
- Normalize features for regularized models  
- Train Ridge, Lasso, and Elastic Net regression models  
- Perform model selection using `GridSearchCV`  
- Evaluate performance via:
  - MSE, RMSE, and R²
  - Residual analysis
  - Model complexity (number of non-zero coefficients)  
- Visualize and interpret results

---

## Project Structure

