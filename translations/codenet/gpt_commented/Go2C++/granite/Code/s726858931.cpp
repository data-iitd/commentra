
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Initialize a new scanner to read input from standard input
void scanInit() {
    setvbuf(stdin, NULL, _IOFBF, 100000); // Set the buffer size to 1MB
}

int main() {
    // Initialize the scanner
    scanInit();

    string s; // Initialize the input string
    getline(cin, s); // Read the input string

    char c = 'a'; // Initialize the current letter to 'a'

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    cout << "None" << endl;

    return 0;
}

// ---- readfunc

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from the input
    return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
    string s;
    getline(cin, s); // Read the next string from the input
    return s; // Return the string
}

// ---- main

int main() {
    // Initialize the scanner
    scanInit();

    // Read the input string
    string s = nextStr();

    // Start checking for the first missing lowercase letter from 'a'
    char c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (int j = 0; j < 26; j++) {
        bool found = false; 