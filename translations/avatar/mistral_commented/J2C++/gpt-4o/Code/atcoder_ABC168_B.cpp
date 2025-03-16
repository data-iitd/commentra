#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for using strings

using namespace std; // Use the standard namespace

int main() { // Define the main function as the entry point of the program

    int K; // Declare an integer variable K
    cin >> K; // Read the first integer K from the input

    string S; // Declare a string variable S
    cin >> S; // Read the next token from the input, which is assumed to be a string S

    if (S.length() <= K) { // Check if the length of the string S is less than or equal to the integer K
        cout << S << endl; // If the condition is true, print the string S to the standard output
    } else { // If the condition is false
        cout << S.substr(0, K) + "..." << endl; // Print the first K characters of the string S followed by "..." to the standard output
    }

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
