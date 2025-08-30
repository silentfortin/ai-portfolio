# 🚘 VisionTechAI – Animal Recognition for Autonomous Driving

> Developed as part of **AI Engineering Master – Week 3**  
> This project builds and evaluates convolutional neural networks (CNNs) to distinguish between vehicles and animals, supporting safer urban mobility for autonomous driving systems.

---

## 📌 Project Overview

VisionTechAI addresses the challenge of **real-time image recognition** for autonomous driving, with a specific focus on identifying **vehicles vs. animals**.  
The system leverages **Convolutional Neural Networks (CNNs)** trained on the **CIFAR-10 dataset**, enabling classification to support **traffic monitoring**, **wildlife protection**, and **accident prevention**.

The project experiments with multiple CNN architectures and optimization strategies to evaluate trade-offs between accuracy, generalization, and computational efficiency.

---

## 🧱 Technologies and Concepts

- ✅ **Python 3.x**  
- ✅ **TensorFlow / Keras**  
- ✅ **NumPy, Matplotlib**  
- ✅ **CNN architectures** (convolution, pooling, dropout, dense layers)  
- ✅ **Image preprocessing and data augmentation**  
- ✅ **Optimizers**: Adam, RMSprop, learning rate scheduling (Cosine Decay)  
- ✅ **Early stopping & model checkpointing**  
- ✅ **Evaluation metrics**: Accuracy, Precision, Recall, AUC  

---

## 🚀 Features

- 🔹 Binary classification task: **vehicles (car, truck, airplane, ship) vs. animals (all other CIFAR classes)**  
- 🔹 Data preprocessing and **data augmentation** (rotation, shifts, flips, zoom, shear)  
- 🔹 Custom CNN models with adjustable depth and dropout regularization  
- 🔹 Comparison of **optimizers (Adam, RMSprop)** and **learning rate schedules**  
- 🔹 Training pipeline with **early stopping** and performance tracking  
- 🔹 Visualization of training curves (accuracy/loss) and residual error analysis  
- 🔹 Model persistence for later deployment and reusability  

---

## 📂 Project Structure

- `dl-autonomous-vehicle.ipynb`: Main notebook with full implementation and experiments  
- `README.md`: Project documentation  

---

## 📊 Experimental Setup & Results

The following CNN configurations are compared:

| Run | Model       | Optimizer                | Architecture (filters, dense) | Regularization | Goal |
| --- | ----------- | ------------------------ | ----------------------------- | -------------- | ---- |
| 1   | CNN base    | **Adam** (lr=1e-3)       | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Baseline with standard setup |
| 2   | CNN base    | **Adam + CosineDecay**   | 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Test whether learning rate scheduling improves Adam |
| 3   | CNN base    | **RMSprop + CosineDecay**| 32 → 64 → 128, Dense=256      | Dropout 0.3–0.5 | Direct comparison with Adam (Run 1 & 2) |
| 4   | CNN reduced | **RMSprop + CosineDecay**| 16 → 32 → 64, Dense=128       | Dropout 0.3     | Stability test with lighter model |
| 5   | CNN extended| **Adam**                 | 32 → 64 → 128 → 256, Dense=512| Dropout 0.4–0.5 | Deeper CNN for higher representational power |
| 6   | CNN extended| **RMSprop + CosineDecay**| 32 → 64 → 128 → 256, Dense=512| Dropout 0.4–0.5 | Check if CosineDecay helps handle complexity |

**Metrics tracked per run:**
- Accuracy (overall classification performance)  
- Precision & Recall (balance between false positives/negatives)  
- AUC (model discriminative power)  

---

## 📝 Notes and Future Work

- The **baseline CNN with Adam** already provides strong accuracy on the binary classification task.  
- **Learning rate scheduling (CosineDecay)** shows potential for stabilizing training in deeper networks.  
- **RMSprop** offers competitive performance, particularly in models with smaller architectures.  
- Future improvements could include:  
  - Transfer learning with pretrained networks (e.g., ResNet, EfficientNet)  
  - Deployment in edge devices for **real-time inference**  
  - Integration with **IoT sensors and traffic monitoring systems**  
  - Expansion to multiclass classification (e.g., distinguishing animal species)  

---

## 📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
All experiments are implemented in **TensorFlow/Keras** using the **CIFAR-10 dataset**.  

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/)  
