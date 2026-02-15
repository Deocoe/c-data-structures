# C Data Structures Lab 🚀

<p align="left">
  <a href="./README.pt-br.md">🇧🇷 Leia em Português</a> |
  <b>🇺🇸 Read in English</b>
</p>

---

This repository contains a collection of classic data structures implemented in **C11**, developed with a focus on manual memory management, performance, and *Clean Code* principles.

The goal of this project is to serve as a high-quality reference library and demonstrate fundamental Computer Science concepts applied at a low level.

## 📦 Implemented Structures

### 1. Dynamic Vector
A resizable array implementation that automatically manages its own capacity.

**Key Features:**
* **1.5x Growth Factor:** Optimized strategy to balance memory fragmentation and reallocation overhead.
* **Smart Memory Management:** Includes `vector_fit_memory` to shrink capacity to the exact data size, eliminating memory waste.
* **Safety (Range Checking):** Strict boundary validation on all access, update, and removal operations to prevent memory corruption.
* **Shifting Logic:** Robust implementation of element shifting for insertions and removals at any index.

---

## 🛠️ Technical Decisions & Clean Code

* **Encapsulation:** Uses `static` functions for internal logic, keeping the public API clean and protected.
* **Modern Typing:** Utilizes `stdbool.h` for logical returns and `size_t` to ensure portability across 32-bit and 64-bit architectures.
* **Error Handling:** Descriptive error messages via `stderr` and defensive programming to prevent *Segmentation Faults*.
* **Performance:** Provides O(1) time complexity for access and update operations.

---

## 🏗️ Build and Run

This project uses **CMake** for build management.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Deocoe/c-data-structures.git](https://github.com/Deocoe/c-data-structures.git)
   cd c-data-structures