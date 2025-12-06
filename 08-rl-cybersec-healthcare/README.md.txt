# DeepGuard – Healthcare Cybersecurity with Reinforcement Learning

> Developed as part of **AI Portfolio – Project 08**  
> This project applies **Reinforcement Learning** to defend a healthcare network against cyber attacks using the `gym-idsgame` environment, combining a **tabular SARSA baseline** and a **Double Deep Q-Network (DDQN)** implemented in PyTorch.

---

## 📌 Project Overview

DeepGuard addresses the problem of **automatically learning defence strategies** for a hospital-like computer network under cyber attack.  
The system models the interaction between an attacker and a defender as a Markov game in `gym-idsgame`, and trains RL agents to **minimize successful intrusions** while adapting to different attacker behaviours.

The project experiments with:

- A **tabular SARSA baseline** on the `idsgame-random_attack-v8` scenario  
- A **DDQN agent** on both `idsgame-random_attack-v8` and `idsgame-maximal_attack-v8`  
- Custom state encodings for tabular and deep RL  
- Exploration scheduling with decaying ε-greedy policies  
- Stability techniques: replay buffer, target network, and gradient clipping  

This repository includes the **final trained agents**, learning curves, and all code needed to reproduce the experiments.

---

## 🧱 Technologies and Concepts

- ✅ Python 3.x  
- ✅ PyTorch  
- ✅ `gym-idsgame` (OpenAI Gym environment)  
- ✅ NumPy, pandas, Matplotlib  
- ✅ Tabular SARSA (on‑policy TD control)  
- ✅ Double Deep Q-Network (DDQN)  
- ✅ Replay buffer & target network  
- ✅ Epsilon‑greedy exploration with exponential decay  
- ✅ Gradient clipping for stabilizing deep RL training  

---

## 🚀 Features

- 🔹 **Healthcare‑inspired cyber range** using `idsgame-random_attack-v8` and `idsgame-maximal_attack-v8`  
- 🔹 Tabular SARSA agent with discrete state encoding (flattened integer tuples)  
- 🔹 DDQN agent with neural state encoder (normalized float32 vectors)  
- 🔹 Separate training runs for **random attacker** and **maximal attacker** scenarios  
- 🔹 Learning curves with per‑episode reward and moving averages  
- 🔹 Greedy evaluation (ε=0) to assess the true quality of the learned policies  
- 🔹 Model checkpoints (`.pt`) and logs for reproducibility  

---

## 📂 Project Structure

- `deep_guard.ipynb`: Main Colab notebook with full implementation and commentary  
- `README.md`: Project documentation
---

## 📊 Experimental Setup

### Environments

- **Random Attack**: `idsgame-random_attack-v8`  
  - Attacker samples actions randomly, providing a stochastic baseline.  
- **Maximal Attack**: `idsgame-maximal_attack-v8`  
  - Attacker follows a stronger, more aggressive policy targeting high‑value nodes.

### SARSA Baseline

- Algorithm: tabular SARSA with ε‑greedy policy  
- State: flattened tuple of integers built from the two observation matrices  
- Episodes: **600**  
- Hyperparameters:
  - Learning rate α = 0.1  
  - Discount factor γ = 0.99  
  - ε from 1.0 → 0.05 with exponential decay  
  - Max 1000 steps per episode  

### DDQN Agent

- Network: 3‑layer MLP, 66‑dim input → 256 → 256 → 33 actions  
- Stabilisation:
  - Replay buffer with capacity 50,000 transitions  
  - Separate target network updated every 50 episodes  
  - Gradient clipping with `max_norm = 10`  

- Training configuration:
  - Episodes: **600** (random & maximal scenarios)  
  - Discount factor γ = 0.99  
  - Batch size = 32  
  - Random attack: learning rate `5e-4`  
  - Maximal attack: learning rate `1e-3`  
  - ε from 1.0 → 0.05 with exponential decay (0.995)

---

## 📊 Key Results

### SARSA (Random Attack v8)

- The 50‑episode moving average stabilizes roughly in the **0.5–0.7** range.  
- With ε close to 0.05 in the final episodes, the agent maintains a **consistently positive reward**, indicating a reliable but tabular defence policy against random attacks.

### DDQN (Random Attack v8)

- The 20‑episode moving average fluctuates roughly between **0.3 and 0.8** over 600 episodes.  
- Greedy evaluation over 10 episodes yields mostly optimal rewards (1.0) with a few failures (‑2.0), showing that the learned DDQN policy is **reasonably effective but not perfectly robust** under stochastic random attacks.

### DDQN (Maximal Attack v8)

- After an initial phase with negative rewards, the 20‑episode moving average steadily increases and stabilizes close to **1.0**.  
- Greedy evaluation consistently returns near‑optimal rewards (often 10/10 episodes at 1.0), demonstrating that the DDQN agent learns a **strong defensive strategy** even against an aggressive maximal attacker.

---

## 📎 License & Credits

This project is part of an individual portfolio for **GreenGuard Solutions / DeepGuard** in the context of healthcare cybersecurity.  
All experiments are implemented in **PyTorch** and use the open‑source `gym-idsgame` environment for cyber‑attack/defence simulation.

Notebook & results:  
[`08-rl-cybersec-healthcare`](https://colab.research.google.com/drive/13wWPeffl92lrIZAbyXNvUroV2ahmvNkQ?usp=sharing)
