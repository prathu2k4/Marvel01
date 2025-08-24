# Titanic - Machine Learning from Disaster 🚢

This repository contains my solution for the [Titanic: Machine Learning from Disaster](https://www.kaggle.com/c/titanic) competition on Kaggle. The goal is to build a predictive model that determines whether a passenger survived the Titanic shipwreck using passenger features such as age, sex, and socio-economic class.

---

## 📌 Competition Overview

* **Objective**: Predict survival (`0 = Did not survive`, `1 = Survived`).
* **Dataset**: Passenger information including demographic, socio-economic, and family-related features.
* **Evaluation Metric**: Accuracy on the test set.

---

## 📂 Repository Structure

```
├── new.ipynb          # Jupyter notebook with EDA, preprocessing, modeling, and submission
├── submission.csv      # Final submission file generated (Survived predictions)
├── README.md           # Documentation
```

---

## ⚙️ Setup & Requirements

Install the required dependencies:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn xgboost
```

Download the dataset from [Kaggle Titanic dataset](https://www.kaggle.com/c/titanic/data) and place `train.csv` and `test.csv` in a `data/` directory.

---

## 🔍 Approach

### 1. Exploratory Data Analysis (EDA)

* Checked distributions of Age, Pclass, Sex, Fare, etc.
* Investigated correlations between features and survival.

### 2. Feature Engineering

* **Title extraction**: Parsed passenger names to extract titles (Mr, Miss, Mrs, etc.), grouped rare ones under "Rare".
* **Family features**: Created `FamilySize` = (SibSp + Parch + 1) and `IsAlone`.
* **Missing values**:

  * `Age` → filled with median.
  * `Embarked` → filled with mode.
  * `Fare` → filled with median (for test set).
* **Encoding**: Converted categorical variables (`Sex`, `Embarked`, `Title`) using `LabelEncoder`.

### 3. Model Training

* **Model used**: `XGBClassifier`

  * `n_estimators=700`
  * `max_depth=4`
  * `learning_rate=0.01`
  * `subsample=0.8`
  * `colsample_bytree=0.8`
* **Validation**:

  * 80/20 train-validation split.
  * 5-fold cross-validation for robust score estimation.

### 4. Submission

* Final predictions generated on `test.csv`.
* Output saved as `submission.csv`.

---

## 📈 Results

* **Validation Accuracy**: \~0.82122905
* **Cross-validation Accuracy**: \~0.83615592
* **Public Leaderboard Score**: **0.75598**

---
