
#include <iostream>
#include <string>

// Define a function named'solve' that takes five arguments: S, T, A, B, and U.
void solve(std::string S, std::string T, int A, int B, std::string U) {

    // Check if S is equal to U. If yes, decrement A.
    if (S == U) {
        A -= 1;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (T == U) {
        B -= 1;
    }

    // Print the updated values of A and B.
    std::cout << A << " " << B << std::endl;

    // Return from the function.
    return;
}

// Define a function named'main' that doesn't take any arguments.
void main() {

    // Define a string variable named 'line' to store the input line.
    std::string line;

    // Read the first line of input from standard input and store it in the 'line' variable.
    std::getline(std::cin, line);

    // Define a stringstream object named'sstream' to tokenize the input line.
    std::stringstream sstream(line);

    // Define a string variable named 'token' to store each token from the input line.
    std::string token;

    // Extract the first token from the input line and assign it to the 'token' variable.
    std::getline(sstream, token,'');

    // Define a string variable named 'S' and assign the value of the 'token' variable to it.
    std::string S = token;

    // Extract the second token from the input line and assign it to the 'token' variable.
    std::getline(sstream, token,'');

    // Define a string variable named 'T' and assign the value of the 'token' variable to it.
    std::string T = token;

    // Extract the third token from the input line and assign it to the 'token' variable.
    std::getline(sstream, token,'');

    // Define an integer variable named 'A' and assign the value of the 'token' variable to it.
    int A = std::stoi(token);

    // Extract the fourth token from the input line and assign it to the 'token' variable.
    std::getline(sstream, token,'');

    // Define an integer variable named 'B' and assign the value of the 'token' variable to it.
    int B = std::stoi(token);

    // Extract the fifth token from the input line and assign it to the 'token' variable.
    std::getline(sstream, token,'');

    // Define a string variable named 'U' and assign the value of the 'token' variable to it.
    std::string U = token;

    // Call the'solve' function with the assigned variables.
    solve(S, T, A, B, U);
}

// If the script is run as the main program, execute the'main' function.
int main() {
    main();
    return 0;
}

