# California Housing Prices – Linear Regression

This project implements **Linear Regression from scratch** (using Gradient Descent) and compares it with **Scikit-learn’s LinearRegression** on the [California Housing Prices dataset](https://scikit-learn.org/stable/datasets/real_world.html#california-housing-dataset).

---

## 📌 Project Objectives

* Implement linear regression **manually** (without ML libraries for training).
* Apply **gradient descent** to minimize error.
* Compare performance with `sklearn.linear_model.LinearRegression`.
* Visualize results with best-fit line and data points.
* Evaluate using **MSE, MAE, R²** metrics.

---

## 📂 Project Structure

```
├── california_housing_lr.ipynb   # Jupyter Notebook with full implementation
├── README.md                     # Project documentation
└── requirements.txt              # Dependencies
```

---

## ⚙️ Setup & Installation

1. Clone this repo:

   ```bash
   git clone https://github.com/your-username/california-housing-lr.git
   cd california-housing-lr
   ```

2. Install dependencies:

   ```bash
   pip install -r requirements.txt
   ```

3. Run the notebook:

   ```bash
   jupyter notebook california_housing_lr.ipynb
   ```

---

## 📊 Results

### Custom Gradient Descent Performance:

* **MSE:** 0.7091
* **MAE:** 0.6299
* **R²:** 0.4589

### Scikit-learn LinearRegression Performance:

* **MSE:** 0.7091
* **MAE:** 0.6299
* **R²:** 0.4589

✅ Both models achieved **identical performance**, confirming the correctness of the manual gradient descent implementation.

---

## 📈 Visualization

Scatter plot of test data with best-fit lines:

* 🔴 Custom Gradient Descent
* 🟢 Scikit-learn LinearRegression

![img](https://github.com/prathu2k4/Marvel01/blob/main/images/lin_reg_op.png)

---

## 🔎 Key Learnings

* Gradient Descent converges to the same solution as the analytical method (OLS).
* Feature scaling is crucial for faster convergence.
* Even with a single feature (`MedInc`), the model explains \~46% of price variance.

---

## 🚀 Next Steps

* Extend implementation to **multiple features**.
* Plot **loss vs. iterations** to visualize gradient descent convergence.
* Experiment with different learning rates and batch sizes.

---

## 🛠️ Tech Stack

* Python
* NumPy, Pandas, Matplotlib
* Scikit-learn

---
