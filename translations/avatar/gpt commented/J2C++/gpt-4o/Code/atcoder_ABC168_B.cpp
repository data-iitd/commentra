#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation

using namespace std;

int main() {
    // Create an integer K to store the maximum length of the string to display
    int K;
    // Read an integer K from the user
    cin >> K;

    // Create a string S to store the input string
    string S;
    // Read a string S from the user
    cin >> S;

    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, print the string S as it is
        cout << S << endl;
    } else {
        // If false, print the first K characters of S followed by "..."
        cout << S.substr(0, K) << "..." << endl;
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
