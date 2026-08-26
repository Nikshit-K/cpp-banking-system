# Terminal Banking System in C++

A lightweight, console-based banking application built using Object-Oriented Programming (OOP) principles in C++.

## 🚀 Features
- **Account Initialization:** Prompts user to set up their account holder name and starting balance.
- **Deposit & Withdraw:** Handles real-time transaction processing with edge-case validation (guards against negative amounts and overdrafts).
- **Encapsulation:** Protects account balance and user details using private member variables.
- **Interactive Menu:** Clean terminal interface driven by a `do-while` loop and `switch-case` control flow.

## 🛠️ Concepts Applied
- **Language:** C++
- **OOP Pillars:** Classes, Objects, Access Specifiers (`private` & `public`), Encapsulation
- **Control Flow:** `do-while` loops, `switch-case`, conditional logic

## 💻 How to Run

1. Clone or download the repository:
   \`\`\`bash
   git clone https://github.com/Nikshit-K/cpp-banking-system.git
   \`\`\`
2. Navigate to the directory and compile using any standard C++ compiler (such as `g++`):
   \`\`\`bash
   g++ -o BankSystem BankSystem.cpp
   \`\`\`
3. Run the executable:
   - On Windows:
     \`\`\`bash
     ./BankSystem.exe
     \`\`\`
   - On Linux/macOS:
     \`\`\`bash
     ./BankSystem
     \`\`\`

## 📌 Future Improvements
- Add persistent storage using File I/O (`<fstream>`) to retain balances after closing.
- Implement multi-user management using `std::vector`.
