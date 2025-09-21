# GreenAI – Flower Recognition Optimization

> Developed as part of **AI Portfolio – Project 07**  
> This project develops and fine-tunes **deep learning models** to classify **flower images** (Daisy & Dandelion) for smart AgriTech automation, supporting real-world innovation in the agriculture sector.

---

## 📌 Project Overview

GreenAI addresses the challenge of **automatically classifying flower species** to enhance data-driven agricultural processes for GreenTech Solutions Ltd.  
The system uses **Transfer Learning** (EfficientNet-B0, timm) and advanced optimization strategies to maximize **accuracy**, **robustness**, and **efficiency**.

The project experimented with:  
- **Baseline feature extraction** (frozen EfficientNet-B0 backbone)  
- **Full fine-tuning** (after 5 epochs, unfreeze backbone & retrain)  
- **Rich data augmentation** (Albumentations)  
- **Learning rate scheduling & regularization**  

This repository includes the **final best-performing model** and all files needed for reproducibility.

---

## 🧱 Technologies and Concepts

- ✅ Python 3.x  
- ✅ PyTorch & TIMM  
- ✅ Albumentations, torchvision  
- ✅ NumPy, pandas  
- ✅ EfficientNet-B0 Transfer Learning  
- ✅ Data preprocessing and augmentation  
- ✅ Optimizer: AdamW with Cosine Annealing LR  
- ✅ Custom fine-tuning and staged training  
- ✅ Early stopping & model checkpointing  
- ✅ Evaluation metrics: Accuracy, Precision, Recall, F1-score, Confusion Matrix  

---

## 🚀 Features

- 🔹 **Binary classification**: Daisy vs Dandelion (real-world flower images)  
- 🔹 Data preprocessing with normalization and extensive augmentations  
- 🔹 Baseline (frozen backbone) vs. fully fine-tuned model comparison  
- 🔹 Automated staged training and optimizer reset  
- 🔹 Training pipeline with early stopping, checkpointing, and LR scheduling  
- 🔹 Visualization of all learning curves and confusion matrices  
- 🔹 Model persistence (`.pt`) and training logs for reproducibility  

---

## 📂 Project Structure

- `cv_flower_recognition.ipynb`: Main notebook with code and documentation  
- `README.md`: Project documentation  
- `data/checkpoint.pt`: Final/best model checkpoint  
- `data/training_history.json`: Training curves and metrics  
- `data/test_results.json`: Classification report on test set  

---

## 📊 Experimental Setup & Results

Two main experimental setups were performed:

| Run | Model Setup             | Training Strategy                  | Optimizer & LR         | Goal               |
| --- | ----------------------- | ---------------------------------- | ---------------------- | ------------------ |
| A   | Baseline EfficientNet-B0| Frozen backbone (feature extractor)| AdamW (lr=1e-3) + Cosine| Establish baseline |
| B   | Fine-tuned EfficientNet | All layers trainable after 5 epochs| AdamW (lr=1e-4) + Cosine| Maximize F1-score |

---

## 📊 Key Results

| Model                    | Test Accuracy | Macro F1-score |
|--------------------------|---------------|----------------|
| **Baseline EfficientNet**|    ~92%        |   ~0.92         |
| **Fine-tuned EfficientNet** | **94%**   | **0.94**       |

✅ Stable convergence, no overfitting  
✅ Improvement over baseline
✅ Balanced results on both Daisy and Dandelion classes  
✅ Robust classification, ready for real-world AgriTech deployment  

---

## 📎 License & Credits

This project is part of an individual portfolio for GreenTech Solutions Ltd.  
All experiments are implemented in **PyTorch** using a real-world flower classification dataset provided in the assignment.

Notebook & results: [cv_flower_recognition.ipynb](https://github.com/silentfortin/ai-portfolio/blob/main/07-cv-flower-recognition/cv_flower_recognition.ipynb)



