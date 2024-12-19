# Rubik's Cube Scrambler and Timer

Welcome to the **Rubik's Cube Scrambler and Timer** project! This program generates random scrambles for 3x3 and 4x4 Rubik's Cubes and includes a timer to track your solving speed. It's a simple alternative to CSTimer and is designed for local use with user authentication and time logging.

---

## Features

- **Random Scramble Generation**: Supports 3x3 and 4x4 Rubik's Cubes.
- **Timer Functionality**: Start and stop the timer using the spacebar.
- **User Authentication**: Create and log in to accounts. Credentials are stored locally.
- **Time Logging**: Tracks and calculates your average solve time.

---

## Getting Started

### Prerequisites

- A **Windows system** (uses Windows-specific headers like `<windows.h>`).
- C++ compiler (e.g., GCC, Clang, or MSVC).
- A text editor or IDE for compiling and running the program.
---
- Or Skipped entirely Via running the .exe - it will automatically run the Program, already complied exe

---

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/JadMustafa/RubixCubeScrambler.git
   ```
2. Navigate to the project directory:
   ```bash
   cd rubiks-cube-scrambler
   ```
3. Compile the program:
   ```bash
   g++ -o scrambler main.cpp
   ```
4. Run the executable:
   ```bash
   ./scrambler
   ```
   #### alternatively, you can just run the .exe 

---

## Usage

1. Launch the program.
2. Choose to log in or create an account.
3. Enter your name and cube size (e.g., `3` or `4x4`).
4. View the generated scramble and decide whether to use the timer.
5. Start the timer by holding the spacebar for 1 second and releasing it.
6. Stop the timer by pressing the spacebar again.
7. View your solve time and your average time.

---

## Example

```text
1. Login
2. Create Account
Choose an option: 1
Enter username: user123
Enter password: password123
Authentication was successful.

Enter your name: Alex
Welcome to Cstimer But Worse!
What are the dimensions of the Cube? (e.g., 3 or 3x3): 3
Random moves: U R' F2 U2 D' L R2 B F' D

Do you want a timer? y/n: y
Hold the spacebar for 1 second to start the timer.
Timer started!
Timer stopped! Elapsed time: 15.2 seconds.
Your average time: 18.4 seconds.
```

---

## File Descriptions

- **`main.cpp`**: The main source code file containing all program logic.
- **`credentials.txt`**: Stores usernames and passwords.
- **`<username>_times.txt`**: Logs solve times for individual users.

---

## Changelog

### Version 1.1 (12/19/2024)
- Added user authentication for local use.
- Enhanced timer functionality.

### Version 1.0 (12/19/2024)
- Initial release with scramble generation and timer.

---

## License

This project is licensed under the MIT License. See the [LICENSE](https://opensource.org/licenses/MIT) file for details.

---

## Disclaimer

The creator of this program is not liable for any damages or losses that may occur from its use. Use it responsibly, and have fun solving!

---

## Contributing

Contributions are welcome! Feel free to fork the repository and submit a pull request with your improvements.

---

## Contact

For questions or feedback, feel free to reach out:
- **Email**: No Publicly accessible Email :)
- **GitHub**: [JadMustafa](https://github.com/JadMustafa)

This software is licensed under the MIT [License](https://opensource.org/licenses/MIT).
It is free to use, modify, and distribute, provided that proper credit is given to the original creator of this program. 
The Creator of this Program is not liable for any damages or losses that may occur from the use of this program.
