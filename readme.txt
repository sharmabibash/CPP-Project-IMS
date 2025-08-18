IMS (Inventory Management System) — Build & Run Guide (Windows, Qt/C++)

────────────────────────────────────────────────────────────────────────────

OVERVIEW
- This project is a Qt/C++ application built with CMake.
- Source lives in: views/, assets/, database/
- Build outputs live in: build/bin (exe), build/lib (libs), build/IMS_autogen (Qt generated)
- You must keep runtime folders (assets, database) next to the exe when running outside Qt Creator.


PREREQUISITES
- Windows 10/11 (x64)
- Qt 6.x (recommended) or Qt 5.15.x, with a Desktop kit:
  • MSVC 2019/2022 64-bit  OR  MinGW-w64 64-bit
- CMake 3.24+
- A C++ compiler matching your Qt kit (MSVC or MinGW)
- (Optional) Ninja or NMake
- (Optional) Git

IMPORTANT PATHS
- CMAKE_PREFIX_PATH must point to your Qt kit root, e.g.:
  MSVC:  C:\Qt\6.6.3\msvc2022_64
  MinGW: C:\Qt\6.6.3\mingw_64
- For Qt 5.15, you can use: -DQt5_DIR=C:\Qt\5.15.2\msvc2019_64\lib\cmake\Qt5

QUICK START (Qt Creator — easiest)
1) Open Qt Creator → “Open Project…” → select the top-level CMakeLists.txt in the project root.
2) Choose a Desktop kit:
   - “Desktop Qt 6.x MSVC 64-bit” (recommended on Windows), or
   - “Desktop Qt 6.x MinGW 64-bit”
3) Configure Project (let CMake run). Set build directory to ./build if prompted.
5) BUILD and Run:
   - Extract the Zip File
   - Open VS Code
   - Press CTRL+SHIFT+P ---> CMake:Build
   - Press CTRL+SHIFT+P ---> CMake:Run without debugging
   - Project will start soon!!.
# After Run the project ::
  - Create an account
  - Login with Email and Password
  - Dashboard will open
  - Product : Add, Edit and Delete
  - Transactions : Sales and checkout
  - Report : Generate invoice, Today sales CSV, Export stocks CSV, Export Transactions CSV
6) Visit GitHub (Optional) : https://github.com/sharmabibash/CPP-Project-IMS

------------------------------------------------ Thank You --------------------------------------------------------
Project Team:
Bibash Kumar Thakur (081BCT024)
Anurag Chaudhary (081BCT019)
Apil Gaire (081BCT020)
--------------------------------------- Pulchowk Campus, Lalitpur -------------------------------------------------
---------------------------------------Submitted To : Mr. Daya Sagar Baral ----------------------------------------
