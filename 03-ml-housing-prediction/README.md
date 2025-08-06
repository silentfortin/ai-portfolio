🏠 RealEstateAI Solutions – Predictive Modeling for Real Estate Pricing

> Developed as part of **AI Engineering Master – Week 2**  
> This project builds predictive models to estimate real estate prices using regularized linear regression techniques.

---

📌 Project Overview

RealEstateAI focuses on creating reliable models to predict housing prices by improving generalization and reducing overfitting with regularization.  
The project implements and compares three linear regression models with regularization:

- **Ridge Regression**  
- **Lasso Regression**  
- **Elastic Net Regression**

Model performance is evaluated using cross-validation, error metrics, and model complexity analysis (sparsity).

---

🧱 Technologies and Concepts

- ✅ **Python 3.x**  
- ✅ **NumPy, Pandas**  
- ✅ **Scikit-learn**  
- ✅ **Matplotlib / Seaborn**  
- ✅ **Linear regression with regularization**  
- ✅ **Cross-validation and hyperparameter tuning (GridSearchCV)**

---

🚀 Features

- 🔹 Data loading and preprocessing, including handling missing values and categorical variables  
- 🔹 Feature normalization suitable for regularized models  
- 🔹 Training and tuning Ridge, Lasso, and Elastic Net regression models  
- 🔹 Model evaluation via MSE, RMSE, R², and residual analysis  
- 🔹 Analysis of model sparsity through count of non-zero coefficients  
- 🔹 Visualization and interpretation of results

---

📂 Project Structure

All analysis is contained in the main notebook, with essential files as follows:

- `RealEstateAI_PricePrediction.ipynb`: Main notebook with full analysis  
- `README.md`: Project description and instructions  

📊 Results Summary

- All three models show similar performance on the test set, with Elastic Net marginally better in MSE and R²  
- Lasso did not eliminate features due to low regularization strength  
- Regularization improved generalization and decreased overfitting compared to the unregularized approach  
- Residual analysis shows heteroscedasticity, suggesting potential benefits from nonlinear models or data transformation

| Model       | Test RMSE    | Test R² | Non-Zero Coefficients |
| ----------- | ------------ | ------- | --------------------- |
| Ridge       | 1,226,043.82 | 0.651   | 12 / 12               |
| Lasso       | 1,228,297.71 | 0.650   | 12 / 12               |
| Elastic Net | 1,224,420.35 | 0.652   | 12 / 12               |

---

📝 Notes and Future Work

- Regularized linear models effectively predict housing prices on this dataset  
- Limited sparsity observed with Lasso and Elastic Net due to low alpha values  
- Future directions may include feature engineering, nonlinear models (e.g., tree-based), and transformations to address heteroscedasticity

---

📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
No external libraries beyond standard data science stack are required.

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/)
