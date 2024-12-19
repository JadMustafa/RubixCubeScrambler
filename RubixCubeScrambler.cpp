/* 
WARNING: This software is licensed under the MIT License. 
It is free to use, modify, and distribute, provided that proper credit is given to the original creator of this program. 
The Creator of this Program is not liable for any damages or losses that may occur from the use of this program.

This program is a simple Rubik's Cube Scrambler that generates a random scramble for a 3x3 or 4x4 Rubik's Cube. 
The program also includes a timer for timing the solving of the Rubik's Cube. 
Note: This is not a finished product; it will be refined in future updates.

Version 1.0: 12/19/2024
    - Initial Release
Version 1.1: 12/19/2024
    - Added User Authentication For Local Host only 
        - Usernames and Passwords are stored in a file, found in the same directory as the program
    - Enhanced Timer Functionality
*/
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <windows.h> 
#include <fstream>  
#include <unordered_map>
#include <vector>
#include <numeric> 

// Function to load user credentials from a file
std::unordered_map<std::string, std::string> loadCredentials() {
    std::unordered_map<std::string, std::string> credentials;
    std::ifstream file("credentials.txt");
    if (file.is_open()) {
        std::string username, password;
        while (file >> username >> password) {
            credentials[username] = password;
        }
        file.close();
    }
    return credentials;
}

// Function to save user credentials to a file
void saveCredentials(const std::unordered_map<std::string, std::string>& credentials) {
    std::ofstream file("credentials.txt");
    if (file.is_open()) {
        for (const auto& pair : credentials) {
            file << pair.first << " " << pair.second << std::endl;
        }
        file.close();
    }
}

// Function to create a new account
bool createAccount(std::unordered_map<std::string, std::string>& credentials) {
    std::string username, password;
    std::cout << "Enter a new username: ";
    std::cin >> username;
    if (credentials.find(username) != credentials.end()) {
        std::cerr << "Username already exists. Please try again." << std::endl;
        return false;
    }
    std::cout << "Enter a new password: ";
    std::cin >> password;
    credentials[username] = password;
    saveCredentials(credentials);
    std::cout << "Account created successfully!" << std::endl;
    return true;
}

// Function to authenticate a user
bool authenticateUser(const std::unordered_map<std::string, std::string>& credentials) {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    auto it = credentials.find(username);
    return (it != credentials.end() && it->second == password);
}

void logTime(const std::string& username, double time) {
    std::ofstream file(username + "_times.txt", std::ios::app);
    if (file.is_open()) {
        file << time << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file for logging." << std::endl;
    }
}

double calculateAverageTime(const std::string& username) {
    std::ifstream file(username + "_times.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading times." << std::endl;
        return 0.0;
    }

    std::vector<double> times;
    double time;
    while (file >> time) {
        times.push_back(time);
    }
    file.close();

    if (times.empty()) {
        return 0.0;
    }

    double sum = std::accumulate(times.begin(), times.end(), 0.0);
    return sum / times.size();
}

int main() {
    std::unordered_map<std::string, std::string> credentials = loadCredentials();
    int choice;
    std::cout << "1. Login\n2. Create Account\nChoose an option: ";
    std::cin >> choice;

    bool authenticated = false;
    if (choice == 1) {
        authenticated = authenticateUser(credentials);
        if (!authenticated) {
            std::cerr << "Authentication failed. Exiting program." << std::endl;
            return 1;
        }
    } else if (choice == 2) {
        if (!createAccount(credentials)) {
            return 1;
        }
        authenticated = true;
    } else {
        std::cerr << "Invalid choice. Exiting program." << std::endl;
        return 1;
    }

    std::string username;
    std::cout << "Enter your name: ";
    std::cin >> username;

    std::string input;
    int CubeSize;
    std::cout << "Welcome to Cstimer But Worse!" << std::endl;
    std::cout << "What are the dimensions of the Cube? (e.g., 3 or 3x3): ";
    std::cin >> input;

    
    if (input.find('x') != std::string::npos) {
        CubeSize = std::stoi(input.substr(0, input.find('x')));
    } else {
        CubeSize = std::stoi(input);
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    if (CubeSize == 3) {
        std::string moves[18] = {
            "U", "U'", "U2",
            "D", "D'", "D2",
            "L", "L'", "L2",
            "R", "R'", "R2",
            "F", "F'", "F2",
            "B", "B'", "B2"
        };

        std::uniform_int_distribution<> dis(0, 17);

        int num_moves = 20; 
        std::cout << "Random moves: ";
        for (int i = 0; i < num_moves; ++i) {
            int random_index = dis(gen);
            std::cout << moves[random_index] << " ";
        }
        std::cout << std::endl;
    } else if (CubeSize == 4) {
        std::string moves[36] = {
            "U", "U'", "U2",
            "Uw", "Uw'", "Uw2",
            "D", "D'", "D2",
            "Dw", "Dw'", "Dw2",
            "L", "L'", "L2",
            "Lw", "Lw'", "Lw2",
            "R", "R'", "R2",
            "Rw", "Rw'", "Rw2",
            "F", "F'", "F2",
            "Fw", "Fw'", "Fw2",
            "B", "B'", "B2",
            "Bw", "Bw'", "Bw2"
        };

        std::uniform_int_distribution<> dis(0, 35);

        int num_moves = 20; 
        std::cout << "Random moves: ";
        for (int i = 0; i < num_moves; ++i) {
            int random_index = dis(gen);
            std::cout << moves[random_index] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Unsupported cube size. Currently only 3x3 and 4x4 are supported." << std::endl;
    }

    std::cout << "Do you want a timer? y/n: ";
    char timerWanted;
    std::cin >> timerWanted;

    if (timerWanted == 'y' || timerWanted == 'Y') {
        std::cout << "Hold the spacebar for 1 second to start the timer." << std::endl;
        bool timerRunning = false;
        int time = 0;

      
        while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                Sleep(1000); // Wait for 1 second
                if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                    std::cout << "Release the spacebar to start the timer." << std::endl;
                    // Wait for the spacebar to be released
                    while (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                        Sleep(10); // Small delay to avoid high CPU usage
                    }
                    std::cout << "Timer started!" << std::endl;
                    timerRunning = true;
                    break;
                }
            }
            Sleep(100); // Add a small delay to avoid high CPU usage (maybe works :D maybe not :/ )
        }

    
        while (timerRunning) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                double elapsedTime = time / 10.0;
                std::cout << "Timer stopped! Elapsed time: " << elapsedTime << " seconds." << std::endl;
                logTime(username, elapsedTime);
                timerRunning = false;
                break;
            }

            Sleep(100);
            time++;
            std::cout << "Elapsed time: " << time / 10.0 << " seconds." << std::endl;
        }
    } else {
        std::cout << "Thank you for using this program, with assurance you will use this instead of cstimer.net, which is heinous." << std::endl;
    }

  
    double averageTime = calculateAverageTime(username);
    std::cout << "Your average time: " << averageTime << " seconds." << std::endl;

    std::cout << "Press Enter to exit...";
    std::cin.ignore(); 
    std::cin.get(); 

    return 0;
}