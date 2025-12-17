# CyberEye — Generative Data Augmentation for Critical Infrastructure Security

> Developed as part of **AI Portfolio – Project 09**  
> This project explores **Generative AI–based data augmentation** for image classification in critical infrastructure security scenarios, combining **image captioning, text paraphrasing, and text-to-image generation** to synthetically expand a limited training dataset.

---

## 📌 Project Overview

CyberEye addresses the challenge of **limited and non-diverse training data** in visual surveillance systems used to protect critical infrastructures such as power plants.  
When real-world security datasets are scarce or difficult to collect, generative models can be leveraged to synthesize new samples and potentially improve model robustness.

In this project, a **multi-stage generative pipeline** is applied to the Oxford-IIIT Pet dataset as a controlled proxy for surveillance imagery:

1. **Image Captioning** (BLIP) to extract semantic descriptions from images  
2. **Text Paraphrasing** (T5) to increase linguistic diversity  
3. **Text-to-Image Generation** (Stable Diffusion) to create synthetic images  
4. **Image Classification** using CNN backbones trained on:
   - the original dataset (baseline)
   - an extended dataset enriched with synthetic images  

The impact of generative augmentation is evaluated using **ResNet-18** and **EfficientNet-B0**, with performance measured on a held-out real test set.

---

## 🧱 Technologies and Concepts

- ✅ Python 3.x  
- ✅ PyTorch & Torchvision  
- ✅ Hugging Face Transformers  
- ✅ Diffusers (Stable Diffusion)  
- ✅ BLIP (image captioning)  
- ✅ T5 (text paraphrasing)  
- ✅ Stable Diffusion v1-4 (text-to-image)  
- ✅ CNN image classification (ResNet-18, EfficientNet-B0)  
- ✅ Synthetic data augmentation pipelines  
- ✅ Evaluation with accuracy, precision, recall, and macro-F1  

---

## 🚀 Features

- 🔹 End-to-end **generative augmentation pipeline** (image → text → image)  
- 🔹 Controlled synthetic data generation under hardware constraints  
- 🔹 Comparison between **baseline** and **extended** training setups  
- 🔹 Multiple backbones to study architecture sensitivity to synthetic data  
- 🔹 Clean train/validation/test separation using only real data for evaluation  
- 🔹 Training curves for loss and accuracy (train/val)  
- 🔹 Reproducible experiments with fixed random seeds  

---

## 📂 Project Structure

- `genai_powerplant.ipynb`: Main Colab notebook with full pipeline and experiments   
- `README.md`: Project documentation  

---

## 📊 Experimental Setup

### Dataset

- **Oxford-IIIT Pet Dataset**
  - Used as a proxy for visual security monitoring
  - Fine-grained, multi-class classification
- Splits:
  - **Train**: real images (+ optional synthetic images)
  - **Validation**: real images only
  - **Test**: real images only

### Synthetic Data Generation

- Captioning: `Salesforce/blip-image-captioning-base`  
- Paraphrasing: `ramsrigouthamg/t5-large-paraphraser-diverse-high-quality`  
- Image generation: `CompVis/stable-diffusion-v1-4`  

To ensure feasibility on Google Colab:
- Maximum source images: **300**
- Max prompts per image: **2**
- Diffusion steps: **25**
- Guidance scale: **7.5**

---

## 🧠 Classification Models

### ResNet-18
- Baseline CNN architecture
- Pretrained on ImageNet
- Fine-tuned on:
  - real-only training set
  - extended training set (real + synthetic)

### EfficientNet-B0
- More parameter-efficient and expressive backbone
- Same training protocol as ResNet-18
- Used to assess whether stronger architectures benefit more from synthetic data

---

## 📊 Evaluation Metrics

All models are evaluated on the **same real test set** using:

- Accuracy  
- Macro Precision  
- Macro Recall  
- Macro F1-score  

Training dynamics are analyzed via:
- Training loss curves  
- Training vs validation accuracy curves  

---

## 📊 Key Results

- **ResNet-18**
  - Synthetic augmentation does not improve performance
  - Slight degradation in accuracy and macro-F1 suggests added noise

- **EfficientNet-B0**
  - Baseline already outperforms ResNet-18
  - Extended training yields **small but consistent gains** in macro metrics

These results indicate that **generative data augmentation is not universally beneficial**, and its effectiveness depends on both data quality and model capacity.

---

## 🔎 Conclusions

This project shows that generative augmentation pipelines must be **carefully controlled and evaluated**, especially in critical infrastructure security contexts where robustness and class-wise reliability are essential.

While synthetic images can enrich training data, uncontrolled generation may introduce noise and degrade performance. Stronger architectures such as EfficientNet-B0 appear more capable of leveraging synthetic data, whereas simpler models may suffer from overfitting or distribution shift.

---

## 📎 License & Credits

This project is part of an individual AI portfolio developed for **CyberEye Solutions**, focusing on generative AI for critical infrastructure security.

All experiments are implemented in **PyTorch**, using open-source models from **Hugging Face**.
