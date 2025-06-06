# 🛠️ Multi-Tool Utility: Salary, Tickets, Class Stats & More 🎟️📊⏱️  
_A C++ console application offering a suite of practical tools: salary calculation, stadium ticket sales, class gender statistics, cinema profit analysis, and time conversion, with persistent history and error logging._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1. [Overview](#-overview)
2. [Key Features](#-key-features)
3. [Screenshots](#-screenshots)
4. [System Requirements](#-system-requirements)
5. [Installation and Setup](#️-installation-and-setup)
6. [Usage Guide](#️-usage-guide)
7. [File Structure & Data Persistence](#-file-structure--data-persistence)
8. [Technical Notes](#-technical-notes)
9. [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**Multi-Tool Utility** by Adrian Lesniak is a C++ console application providing a menu-driven interface for common computational tasks:
- Salary calculation
- Stadium ticket sales revenue
- Class gender percentage statistics
- Cinema profit breakdown
- Time conversion (seconds to minutes/seconds)

All operations are logged to `history.txt`, and errors are recorded with timestamps in `errors.log`. The program features robust input validation, colored console output, and a persistent operation history.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🧮 **Salary Calculator**: Computes total salary from hours worked and hourly rate.
*   🎟️ **Stadium Ticket Sales**: Calculates total revenue from ticket classes A, B, and C.
*   👩‍🎓 **Class Gender Stats**: Computes and displays the percentage of boys and girls in a class.
*   🎬 **Cinema Profit Analyzer**: Calculates gross, net, and distributor profits from ticket sales.
*   ⏱️ **Time Converter**: Converts seconds into minutes and seconds.
*   📜 **History Logging**: All results are appended to `history.txt` with timestamps.
*   🛑 **Error Logging**: Any runtime or input errors are logged to `errors.log`.
*   🖥️ **User-Friendly Interface**: Clear, colored menus and prompts; ASCII art banner; about section.
*   🔄 **Retry/Loop**: Menu-driven loop allows repeated use of all tools until exit.

## 🖼️ Screenshots

_Screenshots of the menu, sample calculations, and history viewing._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
  <img src="screenshots\9.jpg" width="300"/>
</p>

## ⚙️ System Requirements

* **Operating System**: Windows, Linux, or macOS (console/terminal required)
* **C++ Compiler**: C++11 or later (e.g., g++, clang++, MSVC)
* **Standard Libraries**: `<iostream>`, `<iomanip>`, `<fstream>`, `<ctime>`, `<string>`, `<vector>`, `<limits>`, `<thread>`, `<chrono>`
* **Write Permissions**: For `history.txt` and `errors.log` in the working directory

## 🛠️ Installation and Setup

1. **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
2. **Compile the Program**:
    ```bash
    g++ main.cpp -o multitool -std=c++11
    ```
3. **Run the Program**:
    * On Windows: `multitool.exe`
    * On Linux/macOS: `./multitool`

## 💡 Usage Guide

1. Launch the program in your terminal.
2. Use the menu to select an operation:
    - Enter the number for the desired tool (1–5).
    - Follow prompts for input (numbers, ticket counts, etc.).
    - Results are displayed and saved to `history.txt`.
3. View operation history via the menu.
4. View author/about info via the menu.
5. Exit by selecting `0`.

**Input Validation**:  
If you enter invalid data (e.g., letters instead of numbers), the program will prompt you to re-enter and log the error.

## 🗂️ File Structure & Data Persistence

* `main.cpp` — Main C++ source file with all logic and menu
* `history.txt` — Appends all operation results with timestamps
* `errors.log` — Appends error messages with timestamps
* `README.markdown` — This documentation
* `LICENSE` — MIT License

## 📝 Technical Notes

* **Input Validation**: Uses `cin.fail()`, `clear()`, and `ignore()` to ensure only valid numeric input is accepted.
* **Color Output**: Uses ANSI escape codes for colored text (may not display on all Windows terminals).
* **Cross-Platform**: Uses `system("cls")` or `system("clear")` for screen clearing.
* **Thread Sleep**: Uses `std::this_thread::sleep_for` for brief pauses after invalid menu choices.
* **History Viewing**: Reads and displays the contents of `history.txt` from the menu.

## 🤝 Contributing

Contributions are welcome!  
1. Fork the repository.
2. Create a feature branch.
3. Commit and push your changes.
4. Open a Pull Request.

## 📃 License

This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.

## 📧 Contact

Created by **Adrian Lesniak**  
GitHub: https://github.com/adi1985a  
Email: adr.lesniak@gmail.com

---
🛠️ _Practical tools for everyday calculations, all in one place._


