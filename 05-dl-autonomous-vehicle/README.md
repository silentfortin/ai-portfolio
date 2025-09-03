# VisionTechAI – Vehicle vs. Animal Recognition for Autonomous Driving

> Developed as part of **AI Engineering Master – Week 5**  
> This project builds and evaluates convolutional neural networks (CNNs) to distinguish between **vehicles** and **animals**, supporting safer urban mobility for autonomous driving systems.

---

## 📌 Project Overview

VisionTechAI addresses the challenge of **real-time image recognition** for autonomous driving, with a specific focus on identifying **vehicles vs. animals**.  
The system leverages **Convolutional Neural Networks (CNNs)** trained on the **CIFAR-10 dataset**, enabling classification to support **traffic monitoring**, **wildlife protection**, and **accident prevention**.

The project experimented with **different CNN architectures and optimization strategies** to evaluate trade-offs between **accuracy**, **generalization**, and **computational efficiency**.  
This repository includes the **best-performing model (Run A – Baseline CNN)** and all files needed for reproducibility.

---

## 🧱 Technologies and Concepts

- ✅ **Python 3.x**  
- ✅ **TensorFlow / Keras**  
- ✅ **NumPy, Matplotlib, Seaborn**  
- ✅ **CNN architectures** (convolution, pooling, dropout, dense layers)  
- ✅ **Image preprocessing and data augmentation**  
- ✅ **Optimizers**: Adam, RMSprop, Cosine Decay scheduling  
- ✅ **Early stopping & model checkpointing**  
- ✅ **Evaluation metrics**: Accuracy, Precision, Recall, F1-score  

---

## 🚀 Features

- 🔹 **Binary classification**: vehicles (airplane, automobile, ship, truck) vs. animals (all other CIFAR classes)  
- 🔹 Data preprocessing with **normalization and augmentation** (rotation, shifts, flips, zoom, shear)  
- 🔹 Custom CNN architecture with 3 convolutional blocks and a dense layer  
- 🔹 Experimental comparison of **optimizers (Adam, RMSprop)** and **model capacities**  
- 🔹 Training pipeline with **early stopping, checkpointing, and performance logging**  
- 🔹 Visualization of **accuracy/loss curves** and **confusion matrices**  
- 🔹 Model persistence (`.keras`, `.json`, `.csv`, `.npy`) for reproducibility  

---

## 📂 Project Structure

- `dl-autonomous-vehicle.ipynb`: Main notebook with full implementation  
- `README.md`: Project documentation  
- `best_model_runA.keras`: Saved best-performing model (Run A)  
- `history_runA.csv`: Training history of Run A  
- `metrics_runA.json`: Evaluation metrics of Run A  
- `x_test_norm_cnn.npy, y_test_bin.npy`: Test data for reproducibility  

---

## 📊 Experimental Setup & Results

Three experimental runs were performed to test different trade-offs:

| Run | Model       | Optimizer & Schedule       | Architecture (filters, dense) | Regularization | Goal |
| --- | ----------- | -------------------------- | ----------------------------- | -------------- | ---- |
| A   | CNN base    | **Adam** (lr=1e-3)         | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Baseline, establish standard performance |
| B   | CNN base    | **RMSprop + CosineDecay**  | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Assess impact of RMSprop + LR scheduling |
| C   | CNN light   | **Adam** (lr=1e-3)         | 16 → 32 → 64, Dense=128       | Dropout 0.3     | Trade-off between accuracy and efficiency (edge deployment) |

### Results summary

---

## 📊 Key Results (Run A – Baseline CNN)

| Metric      | Vehicle | Non-Vehicle | Overall |
|-------------|---------|-------------|---------|
| **Accuracy** |   –     |     –       | **96.2%** |
| **Precision** | 0.962 | 0.962       |   –     |
| **Recall**    | 0.942 | 0.975       |   –     |
| **F1-score**  | 0.952 | 0.969       |   –     |

✅ Stable convergence with no signs of overfitting  
✅ Balanced precision–recall across both classes  
✅ ~6% of vehicles misclassified as non-vehicles, ~2% of non-vehicles misclassified as vehicles  

---

- **Run B (RMSprop + CosineDecay)**: 95.8% accuracy, slightly lower precision on vehicles but smoother validation dynamics.  
- **Run C (Light CNN)**: 95.3% accuracy, only marginally worse than Run A despite reduced capacity, showing efficiency potential.  

👉 The repository includes **Run A only**, as it represents the best trade-off between accuracy and complexity.

---

## 📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
All experiments are implemented in **TensorFlow/Keras** using the **CIFAR-10 dataset**.  

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/)  

