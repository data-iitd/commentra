#include <iostream>
#include <string>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    int K;
    string S;

    // Read an integer K from the user
    cin >> K;

    // Read a string S from the user
    cin >> S;

    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, print the string S as it is
        cout << S << endl;
    } else {
        // If false, truncate the string to the first K characters and append "..."
        cout << S.substr(0, K) + "..." << endl;
    }

    return 0;
}

