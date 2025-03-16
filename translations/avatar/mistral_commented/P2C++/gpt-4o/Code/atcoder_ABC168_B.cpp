#include <iostream>
#include <string>

using namespace std;

// Define the main function
int main() {
    // Read the integer K from the standard input
    int K;
    cin >> K;

    // Read a string S from the standard input
    string S;
    cin >> S;

    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If the condition is true, print the string S
        cout << S << endl;
    } else {
        // If the condition is false, print a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        cout << S.substr(0, K) << "..." << endl;
    }

    return 0;
}

// <END-OF-CODE>
