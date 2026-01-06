# OS-File-Memory-Allocation
Bitmap and Linked List Allocation Algorithms
# Operating Systems – File and Memory Allocation Algorithms

## Course
Operating Systems and Computer Hardware

## Project Topic
Implementation and Comparison of File Allocation and Memory Allocation Algorithms

---

## 📌 Project Overview

This project implements and compares different allocation strategies used in operating systems.  
The focus is on **file allocation methods** (Bitmap and Linked List) and **memory allocation strategies**
(Best Fit, Worst Fit, and Next Fit).

The goal is to understand how different allocation techniques affect:
- Allocation speed
- Fragmentation
- Disk / memory utilization

All implementations were written in **C** and **Python** and tested using fixed allocation traces.

---

## 📁 Project Structure


---

## 🧠 File Allocation Algorithms

### 1️⃣ Bitmap Allocation
- Uses a bitmap where:
  - `0` = free block
  - `1` = allocated block
- Requires **consecutive free blocks**
- Sensitive to **external fragmentation**

Implemented in:
- `bitmap_ai.c` (initial AI-generated version)
- `bitmap_human.c` (rewritten, simplified, and commented)

---

### 2️⃣ Linked List Allocation
- Each block points to the next block
- Blocks **do not need to be consecutive**
- More flexible under fragmentation

Implemented in:
- `linkedlist_ai.c` (initial AI-generated version)
- `linkedlist_human.c` (rewritten, simplified, and commented)

---

## 🧠 Memory Allocation Algorithms (Linked List Based)

Implemented in **Python**:

### ✔ Best Fit
- Chooses the smallest free block that fits
- Reduces wasted space
- Creates small fragments quickly

### ✔ Worst Fit
- Chooses the largest free block
- Preserves large blocks longer
- Can waste space

### ✔ Next Fit
- Continues searching from the last allocation position
- Faster in practice
- Causes uneven fragmentation

Implemented in:
- `memory_allocator.py`

---

## 🧪 Experiments Performed

### 🔹 Allocation Trace
- Fixed allocation sequences were used
- Disk or free list state printed after each operation

### 🔹 Fragmentation Test
- Tested large allocation after fragmentation
- Compared success/failure of each algorithm

### 🔹 Speed Test
- Multiple allocation and free cycles
- Observed relative performance differences

---

## 📊 Observations

- Bitmap allocation may fail even when enough total space exists due to fragmentation
- Linked list allocation succeeds more often in fragmented conditions
- Best Fit creates small fragments quickly
- Worst Fit preserves large blocks longer
- Next Fit is typically the fastest but creates uneven fragmentation

---

## 🧾 Author’s Note

The final versions of the code, experiments, and explanations were written and organized manually.
AI-generated drafts were used only as a starting reference and were rewritten with simpler logic,
clearer variable names, and full understanding of each line.

---

## ✅ Conclusion

This project demonstrates how allocation strategies directly impact fragmentation and performance.
Practical implementation and testing made the theoretical concepts of operating systems clearer
and easier to understand.
