# GourmetAI – Food Image Classification Optimization

> Developed as part of **AI Engineering Master – Week 6**  
> This project develops and fine-tunes **deep learning models** to classify **food images** into 14 categories, supporting innovation in the food-tech sector.

---

## 📌 Project Overview

GourmetAI tackles the challenge of **accurately classifying food images** to enhance **user experience** and **business processes** in the food industry.  
The system leverages **Transfer Learning with ResNet50** and advanced optimization strategies to improve **accuracy**, **generalization**, and **efficiency**.  

The project experimented with:  
- **Baseline feature extraction** (frozen ResNet backbone)  
- **Gradual unfreezing fine-tuning** (classifier → layer4 → layer3)  
- **Regularization & learning rate scheduling**  

This repository includes the **best-performing fine-tuned model** and all files needed for reproducibility.

---

## 🧱 Technologies and Concepts

- ✅ Python 3.x  
- ✅ PyTorch & Torchvision  
- ✅ NumPy, Matplotlib, Seaborn  
- ✅ ResNet50 Transfer Learning  
- ✅ Data preprocessing and augmentation  
- ✅ Optimizers: AdamW with Cosine Annealing LR  
- ✅ Gradual unfreezing for fine-tuning  
- ✅ Early stopping & model checkpointing  
- ✅ Evaluation metrics: Accuracy, Precision, Recall, F1-score, Confusion Matrix  

---

## 🚀 Features

- 🔹 Multi-class classification: 14 food categories (e.g., *Donut, Fries, Sushi, Ice Cream*)  
- 🔹 Data preprocessing with normalization and augmentation (crop, rotation, color jitter, flips)  
- 🔹 Baseline vs. fine-tuned model comparison  
- 🔹 Gradual unfreezing strategy to improve performance  
- 🔹 Training pipeline with early stopping, checkpointing, and learning rate scheduling  
- 🔹 Visualization of accuracy/loss curves and confusion matrices  
- 🔹 Model persistence (`.pth`) for reproducibility  

---

## 📂 Project Structure

- `food_image_classification_optimization.ipynb`: Main notebook with full implementation  
- `README.md`: Project documentation  
- `baseline_model.pth`: Saved baseline model (feature extractor)  
- `best_finetuned_model.pth`: Best-performing fine-tuned model  
- `Visualization results`: accuracy curves, confusion matrix, predictions 

---

## 📊 Experimental Setup & Results

Two main experimental setups were performed:

| Run | Model Setup             | Training Strategy                   | Optimizer & LR          | Goal               |
| --- | ----------------------- | ----------------------------------- | ----------------------- | ------------------ |
| A   | Baseline ResNet50       | Frozen backbone, classifier only     | AdamW (lr=1e-3)         | Establish baseline |
| B   | Fine-tuned ResNet50     | Gradual unfreezing: fc → layer4 → layer3 | AdamW + CosineAnnealing | Improve performance|

---

## 📊 Key Results

| Model                  | Test Accuracy | Macro F1-score |
|-------------------------|---------------|----------------|
| **Baseline ResNet50**   | 81.43%        | 0.8147         |
| **Fine-tuned ResNet50** | **88.36%**    | **0.8838**     |

✅ Stable convergence with no overfitting  
✅ **Significant improvement over baseline (~ +7%)**  
✅ Balanced performance across 14 food classes  
✅ Robust classification of complex categories (e.g., *Sushi, Donut, Fries*)  

---

## 📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
All experiments are implemented in **PyTorch** using the **Food Classification dataset** provided in the course.  

GitHub: [ai-portfolio](https://github.com/silentfortin/ai-portfolio/edit/main/06-dl-pytorch-food/)
