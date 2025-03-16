#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std;

int main() {
    int n, k; // Declare integers n and k
    string a; // Declare a string a

    cin >> n >> k; // Read integers n and k from the user
    cin >> a; // Read the string a from the user

    // Check if k is greater than n/2
    if (k > n / 2) {
        // Move right until k equals n
        while (k < n) {
            cout << "RIGHT" << endl; // Print "RIGHT"
            k++; // Increment k
        }
    } else {
        // Move left until k equals 1
        while (k > 1) {
            cout << "LEFT" << endl; // Print "LEFT"
            k--; // Decrement k
        }
    }

    // If k equals 1, print each character of the string a starting from the first character and moving rightwards
    if (k == 1) {
        for (int i = 0; i < a.length(); i++) {
            cout << "PRINT " << a[i] << endl; // Print the character and then move right
            if ((i + 1) < a.length()) {
                cout << "RIGHT" << endl; // Print "RIGHT" if it's not the last character
            }
        }
    } else {
        // If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
        for (int i = a.length() - 1; i >= 0; i--) {
            cout << "PRINT " << a[i] << endl; // Print the character and then move left
            if ((i - 1) >= 0) {
                cout << "LEFT" << endl; // Print "LEFT" if it's not the first character
            }
        }
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
