import streamlit as st
import pandas as pd
import joblib

st.set_page_config(
    page_title="Credit Risk Prediction",
    page_icon="💳",
    layout="centered"
)



from pathlib import Path
import os

BASE_DIR = Path(__file__).resolve().parent

st.write("Current directory:", BASE_DIR)
st.write("Files in directory:", os.listdir(BASE_DIR))

model = joblib.load(BASE_DIR / "catBoost.pkl")
columns = joblib.load(BASE_DIR / "columns.pkl")

st.title("💳 Credit Risk Prediction System")
st.write("Predict whether a customer is likely to default on a loan.")

st.divider()





person_income = st.number_input(
    "Annual Income",
    min_value=0,
    value=50000
)

loan_percent_income = st.slider(
    "Loan Percent of Income",
    0.0,
    1.0,
    0.20,
    step=0.01
)

loan_int_rate = st.number_input(
    "Interest Rate (%)",
    min_value=0.0,
    max_value=50.0,
    value=10.0
)

loan_amnt = st.number_input(
    "Loan Amount",
    min_value=0,
    value=10000
)

person_emp_length = st.number_input(
    "Employment Length (Years)",
    min_value=0.0,
    value=5.0
)

loan_grade = st.selectbox(
    "Loan Grade",
    ["A","B","C","D","E","F","G"]
)

home = st.selectbox(
    "Home Ownership",
    ["MORTGAGE","OWN","RENT","OTHER"]
)

default = st.selectbox(
    "Previous Default",
    ["No","Yes"]
)





if st.button("Predict"):

    data = dict.fromkeys(columns, 0)

    
    data["person_income"] = person_income
    data["loan_percent_income"] = loan_percent_income
    data["loan_int_rate"] = loan_int_rate
    data["loan_amnt"] = loan_amnt
    data["person_emp_length"] = person_emp_length

    
    if loan_grade == "D":
        data["loan_grade_D"] = 1
    elif loan_grade == "E":
        data["loan_grade_E"] = 1
    elif loan_grade == "F":
        data["loan_grade_F"] = 1
    elif loan_grade == "G":
        data["loan_grade_G"] = 1

    
    if home == "RENT":
        data["person_home_ownership_RENT"] = 1
    elif home == "OWN":
        data["person_home_ownership_OWN"] = 1

    
    if default == "Yes":
        data["cb_person_default_on_file_Y"] = 1

    input_df = pd.DataFrame([data])

    prediction = model.predict(input_df)[0]
    probability = model.predict_proba(input_df)[0][1]

    st.divider()

    st.subheader("Prediction Result")

    if prediction == 1:
        st.error("🔴 High Credit Risk")
    else:
        st.success("🟢 Low Credit Risk")

    st.metric(
        "Probability of Default",
        f"{probability*100:.2f}%"
    )

    st.subheader("Input Summary")
    st.dataframe(input_df)
