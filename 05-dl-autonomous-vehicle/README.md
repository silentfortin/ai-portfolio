# 🚘 VisionTechAI – Vehicle vs. Animal Recognition for Autonomous Driving

> Developed as part of **AI Engineering Master – Week 5**  
> This project builds and evaluates convolutional neural networks (CNNs) to distinguish between **vehicles** and **animals**, supporting safer urban mobility for autonomous driving systems.

---

## 📌 Project Overview

VisionTechAI addresses the challenge of **real-time image recognition** for autonomous driving, with a specific focus on identifying **vehicles vs. animals**.  
The system leverages **Convolutional Neural Networks (CNNs)** trained on the **CIFAR-10 dataset**, enabling classification to support **traffic monitoring**, **wildlife protection**, and **accident prevention**.

The project experiments with **different CNN architectures and optimization strategies** to evaluate trade-offs between **accuracy**, **generalization**, and **computational efficiency**.

---

## 🧱 Technologies and Concepts

- ✅ **Python 3.x**  
- ✅ **TensorFlow / Keras**  
- ✅ **NumPy, Matplotlib, Seaborn**  
- ✅ **CNN architectures** (convolution, pooling, dropout, dense layers)  
- ✅ **Image preprocessing and data augmentation**  
- ✅ **Optimizers**: Adam, RMSprop, Cosine Decay scheduling  
- ✅ **Early stopping & model checkpointing**  
- ✅ **Evaluation metrics**: Accuracy, Precision, Recall, AUC  

---

## 🚀 Features

- 🔹 **Binary classification**: vehicles (car, truck, airplane, ship) vs. animals (all other CIFAR classes)  
- 🔹 Data preprocessing with **normalization and augmentation** (rotation, shifts, flips, zoom, shear)  
- 🔹 Custom CNNs with variable depth, dropout, and dense layers  
- 🔹 Experimental comparison of **optimizers (Adam, RMSprop)** and **learning rate scheduling**  
- 🔹 Full training pipeline with **early stopping, checkpointing, and performance logging**  
- 🔹 Visualization of **accuracy/loss curves** and **confusion matrices**  
- 🔹 Model persistence (`.keras`, `.json`, `.csv`, `.npy`) for reproducibility  

---

## 📂 Project Structure

- `dl-autonomous-vehicle.ipynb`: Main notebook with full implementation and experiments  
- `README.md`: Project documentation  
- `best_model.keras`: Saved best-performing model  
- `history_runX.csv`: Training history per run  
- `metrics_runX.json`: Evaluation metrics per run  
- `x_test_norm_cnn.npy, y_test_bin.npy`: Test data for reproducibility  

---

## 📊 Experimental Setup & Results

Three main runs were performed to test different trade-offs:

| Run | Model       | Optimizer & Schedule       | Architecture (filters, dense) | Regularization | Goal |
| --- | ----------- | -------------------------- | ----------------------------- | -------------- | ---- |
| A   | CNN base    | **Adam** (lr=1e-3)         | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Baseline, establish standard performance |
| B   | CNN base    | **RMSprop + CosineDecay**  | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Assess impact of RMSprop + LR scheduling |
| C   | CNN light   | **Adam** (lr=1e-3)         | 16 → 32 → 64, Dense=128       | Dropout 0.3     | Trade-off between accuracy and efficiency (edge deployment) |

**Metrics tracked per run**:  
- Accuracy  
- Precision & Recall  
- F1-score  

### Notes
- Run B investigates the effect of **changing the optimizer + adding a CosineDecay learning rate schedule** while keeping the convolutional backbone identical to Run A.  
- Run C explores **reduced-capacity architecture** (fewer filters / smaller dense) while keeping Adam to isolate the effect of model capacity on accuracy vs. efficiency.  
- All runs use the same preprocessing, augmentation, batch size and training protocol (where applicable) to ensure a fair comparison.

👉 Example (Run A – Baseline):

- **Accuracy:** ~81%  
- **Precision (vehicle):** 0.69  
- **Recall (vehicle):** 0.98  
- **Precision (non-vehicle):** 0.98  
- **Recall (non-vehicle):** 0.70  

---

## 📝 Notes 

- The **baseline CNN with Adam (Run A)** shows very high recall for vehicles but weaker precision, leading to many false positives.  
- The **RMSprop + CosineDecay setup (Run B)** stabilizes recall but results in an overall drop in accuracy compared to the baseline.  
- The **lightweight CNN with Adam (Run C)** achieves a reasonable trade-off between accuracy and model complexity, making it more suitable for deployment on edge devices.  

---

## 📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
All experiments are implemented in **TensorFlow/Keras** using the **CIFAR-10 dataset**.  

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/)  
