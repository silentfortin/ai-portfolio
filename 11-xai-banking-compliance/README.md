# XAI-MNIST — Explainable AI on MNIST with DenseNet121

> Developed as part of an **AI Portfolio – XAI Notebook**  
> This project demonstrates an end-to-end **Explainable AI (XAI)** workflow on MNIST, including **fine-tuning DenseNet121** and comparing multiple explanation families (gradient-based, perturbation-based, game-theoretic, and CAM). 

---

## Project Overview

The notebook tackles the challenge of interpreting and diagnosing a vision classifier’s decisions by analyzing both a **correct** and an **incorrect** prediction.
A pretrained **DenseNet121 (ImageNet)** is adapted to MNIST by freezing the convolutional feature extractor and replacing the final classifier with a **10-class linear head**, then fine-tuned on MNIST. 

Main pipeline: [file:1]  
1. MNIST preprocessing to match ImageNet models (resize, channel replication, normalization).
2. Fine-tuning and evaluation on the MNIST test set.
3. Automatic selection of one **GOOD** (correctly classified) and one **BAD** (misclassified) sample. 
4. Generation and comparison of XAI attribution maps: **Integrated Gradients, Occlusion, SHAP (GradientExplainer), Grad-CAM**.

---

## Technologies and Concepts

- Python 3.x (Google Colab).  
- PyTorch & Torchvision (model training and MNIST dataset).
- DenseNet121 pretrained on ImageNet + MNIST fine-tuning (classifier head only). 
- Captum: Integrated Gradients, Occlusion, LayerGradCam. 
- SHAP: GradientExplainer for attribution maps.
- “GOOD vs BAD” analysis to inspect reliability and failure modes. 

---

## Features

- Lightweight transfer learning setup: frozen backbone + 10-class head. 
- Multi-method interpretability workflow covering the main saliency explanation families.   
- Fair visual comparison via min-max normalization of attribution maps to a common 0–1 scale. 
- Automated selection of representative correct/incorrect test samples for qualitative diagnosis. 
- Reproducibility: fixed seeds (Torch/Numpy) and explicit device configuration (GPU if available).

---

## Project Structure

- `xai.ipynb`: main notebook (training + evaluation + XAI visualizations).
- `README.md`: project documentation (this file). 

---

## Experimental Setup

### Dataset

- **MNIST** via `torchvision.datasets`. 
- 10 classes (digits 0–9), 60,000 training images and 10,000 test images, original size 28×28 grayscale. 
- Preprocessing to fit DenseNet121 input:  
  - Resize 28×28 → 224×224. 
  - Replicate grayscale channel to 3 channels. 
  - Normalize with ImageNet mean/std. 

### Training

- Model: `torchvision.models.densenet121` pretrained on ImageNet. 
- Feature extractor frozen; final classifier replaced with `Linear(in_features, 10)` and trained on MNIST. 
- Loss: CrossEntropy; optimizer: Adam on classifier parameters; training for 4 epochs. 
- Reported final performance: Train Accuracy **95.71%**, Test Accuracy **96.14%**. 

### XAI Methods

Implemented and compared methods: [file:1]  
- **Integrated Gradients** (gradient-based). [file:1]  
- **Occlusion** (perturbation-based). [file:1]  
- **SHAP GradientExplainer** (game-theoretic / gradient SHAP style explanations). 
- **Grad-CAM** (class activation mapping on the last convolutional block).

---

## GOOD vs BAD Analysis

The notebook identifies one **GOOD** sample (correct prediction) and one **BAD** sample (misclassification) and produces a 2×4 grid of attribution maps (IG / Occlusion / SHAP / Grad-CAM).  
This makes it possible to compare how explanation patterns differ between confident, stroke-aligned evidence (often seen in correct predictions) and more diffuse or ambiguous evidence (often seen in errors). 

---

## How to Run

1. Open `xai.ipynb` in Google Colab (GPU recommended). 
2. Run all cells in order (dependency install, training, sample selection, saliency generation).
3. Inspect outputs: training curves + final 2×4 saliency grid for GOOD/BAD examples. 
