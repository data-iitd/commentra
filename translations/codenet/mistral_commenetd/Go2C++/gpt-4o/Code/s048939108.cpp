#include <iostream>
#include <string>

using namespace std;

// Minimum function
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Maximum function
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    string S;

    // Read the first string from the standard input
    cin >> S;

    // Check if the string starts with "YAKI"
    if (S.rfind("YAKI", 0) == 0) {
        cout << "Yes" << endl; // Print "Yes" if the condition is true
    } else {
        cout << "No" << endl; // Print "No" if the condition is false
    }

    return 0;
}

// <END-OF-CODE>
