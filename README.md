# Terminal Multi-User Banking System in C++

A robust, console-based multi-user banking application built using Object-Oriented Programming (OOP) principles and dynamic memory structures in C++.

## 🚀 Features
- **Multi-User Architecture:** Supports creating and managing multiple distinct bank accounts dynamically in memory using `std::vector`.
- **Account Initialization:** Prompts user to set up their account holder name and starting balance, with strict validation to prevent duplicate account numbers.
- **Deposit & Withdraw:** Handles real-time transaction processing with edge-case validation (guards against negative amounts, zero-value deposits, and overdrafts).
- **Input Stream Hardening:** Sanitizes terminal input buffers against invalid non-numeric inputs (like typing letters instead of numbers) to prevent stream failures and infinite loop crashes.
- **Encapsulation:** Protects account balances and user details using private member variables.
- **Interactive Menu:** Clean terminal interface driven by a `do-while` loop and `switch-case` control flow.
- **Persistent Storage:** Automatically reads existing records on startup and serializes all active accounts back to disk (`accounts.txt`) upon exit using `<fstream>`.
  
## 🛠️ Concepts Applied
- **Language:** C++
- **OOP Pillars:** Classes, Objects, Access Specifiers (`private` & `public`), Encapsulation
- **Data Structures:** Dynamic Arrays via `std::vector`
- **File I/O:** Sequential file parsing and serialization using `<fstream>`
- **Robust Input Handling:** Stream error-flag recovery (`cin.clear()`) and buffer flushing (`cin.ignore()`)
- **Control Flow:** `do-while` loops, `switch-case`, conditional logic

## 💻 How to Run

1. Clone or download the repository:
   ```bash
   git clone https://github.com/Nikshit-K/cpp-banking-system.git
   ```
2. Navigate to the directory and compile using any standard C++ compiler (such as `g++`):
   ```bash
   g++ -o BankSystem BankSystem.cpp
   ```
3. Run the executable:
   - On Windows:
     ```bash
     .\BankSystem.exe
     ```
   - On Linux/macOS:
     ```bash
     ./BankSystem
     ```

## 🔮 Future Improvements
- [x] Migrate from single account to multi-user vector architecture
- [x] Implement persistent data storage (File I/O)
- [x] Harden input streams against invalid character loops
- [ ] Add PIN/password authentication for individual accounts
- [ ] Implement account-to-account money transfers
- [ ] Track and save transaction history (mini-statements)
