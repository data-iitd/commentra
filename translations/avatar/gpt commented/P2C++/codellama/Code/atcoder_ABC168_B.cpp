#include <iostream>
#include <string>
using namespace std;

int main() {
    // Read an integer input K from the user
    int K;
    cin >> K;
    
    // Read a string input S from the user
    string S;
    cin >> S;
    
    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, return the original string S
        return S;
    }
    
    // If the length of S is greater than K, return the first K characters followed by '...'
    return S.substr(0, K) + "...";
}

// Entry point of the program
int main() {
    // Call the main function and print its result
    cout << main() << endl;
}

