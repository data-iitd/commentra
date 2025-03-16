#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    Scanner in;
    
    // Read an integer K from the user, which represents the maximum length of the string to display
    int K;
    cin >> K;
    
    // Read a string S from the user
    string S;
    cin >> S;
    
    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {
        // If true, print the string S as it is
        cout << S << endl;
    } else {
        // If false, print the first K characters of S followed by "..."
        cout << S.substr(0, K) << "..." << endl;
    }
    
    // Close the scanner to prevent resource leaks
    in.close();
    
    return 0;
}

