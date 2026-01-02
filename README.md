# APC – Arbitrary Precision Calculator

## 📌 Project Overview

**APC (Arbitrary Precision Calculator)** is a command-line application written in **C** that performs arithmetic operations on **very large integers**, beyond the limits of built-in data types like `int` or `long long`.

The project internally represents numbers using a **Doubly Linked List**, where each node stores a single digit. Arithmetic operations are implemented using **manual logic**, similar to how calculations are done on paper.

---

## 👤 Author Information

- **Name:** Deekshith Kumar A.  
- **Date:** 18/12/2025  
- **Project Type:** Data Structures (Double Linked Lists)  
- **Language:** C  

---

## ⚙️ Key Features

- Supports **very large integers**
- Handles **positive and negative numbers**
- No dependency on big integer libraries
- Uses **Doubly Linked Lists** for digit-by-digit operations
- Clean modular design with reusable functions

---

## 🧠 Internal Data Representation

Each digit of a number is stored in a node of a doubly linked list:


This allows easy traversal from both **MSD → LSD** and **LSD → MSD**, which is crucial for arithmetic operations.

---

## ➕ Supported Operations

### 1️⃣ Addition (`addition`)
- Adds two large numbers digit by digit from the **least significant digit**
- Handles carry propagation
- Stores the result in a new linked list

### 2️⃣ Subtraction (`subtraction`)
- Performs subtraction using **borrow logic**
- Compares operands to handle negative results
- Removes leading zeros from the result

### 3️⃣ Multiplication (`multiplication`)
- Implements **long multiplication**
- Generates partial products
- Uses the addition function to accumulate results

### 4️⃣ Division (`division`)
- Performs division using **repeated subtraction**
- Handles division by zero safely
- Works with very large numbers

---

## 🚨 Error Handling

Invalid operators are detected

Division by zero is handled safely

Leading zeros are removed from results

Zero results are displayed correctly without sign issues

---

## 🎯 Learning Outcomes

Strong understanding of Doubly Linked Lists

Manual implementation of arithmetic logic

Handling large data beyond primitive limits

Modular C programming

Command-line argument processing

---

## 🚀 Future Enhancements

Support for modulus operation

Floating-point arithmetic

Expression parsing (e.g., 123 + 45 * 6)

Improved division algorithm for performance

---

## 📜 Conclusion

This project demonstrates how data structures can overcome hardware limitations by implementing arithmetic logic at a low level.
It is an excellent example of combining C programming with core DSA concepts.
