#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read a string from the input
    string S;
    cin >> S;

    // Check if the string starts with "YAKI" and print the corresponding response
    if (S.rfind("YAKI", 0) == 0) { // rfind with position 0 checks for prefix
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// min function to return the smaller of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// max function to return the larger of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Scanner class to handle buffered input reading
class Scanner {
public:
    Scanner() {
        // Constructor can be used for initialization if needed
    }

    string next() {
        string word;
        cin >> word; // Read the next word
        return word; // Return the word
    }

    string nextLine() {
        string line;
        cin.ignore(); // Ignore the newline character
        getline(cin, line); // Read the entire line
        return line; // Return the line
    }

    int nextInt() {
        int v;
        cin >> v; // Read the next integer
        return v; // Return the integer
    }

    void nextIntArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cin >> arr[i]; // Read space-separated integers into the array
        }
    }
};

// <END-OF-CODE>
