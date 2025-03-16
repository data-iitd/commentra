
#include <bits/stdc++.h>

using namespace std;

// Define a global variable for input reading
string input;

// Define a function to read input from the user
void readInput() {
    getline(cin, input); // Read the input line
}

// Define a function to get the next token from the input
string getNextToken() {
    string token;
    int start = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] =='') {
            token = input.substr(start, i - start);
            start = i + 1;
        }
    }
    token = input.substr(start);
    return token;
}

// Define a function to get the next line from the input
string getNextLine() {
    string line = input;
    input = "";
    return line;
}

// Define a function to print the output
void printOutput(string output) {
    cout << output << endl;
}

// Define a function to get the maximum of two integers
int getMax(int a, int b) {
    return (a > b)? a : b;
}

// Define a function to get the minimum of two integers
int getMin(int a, int b) {
    return (a < b)? a : b;
}

// Define a function to perform ceiling division of two integers
int getCeilDiv(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    readInput(); // Read the input line
    int N = stoi(getNextToken()); // Convert the first token to an integer
    vector<int> T(N), A(N); // Initialize vectors for T and A
    for (int i = 0; i < N; i++) {
        T[i] = stoi(getNextToken()); // Convert the next token to an integer
        A[i] = stoi(getNextToken()); // Convert the next token to an integer
    }
    int t = T[0], a = A[0]; // Initialize t and a with the first pair
    for (int i = 1; i < N; i++) {
        int r = getMax(getCeilDiv(t, T[i]), getCeilDiv(a, A[i])); // Calculate the required multiplier
        t = T[i] * r; // Update t based on the multiplier
        a = A[i] * r; // Update a based on the multiplier
    }
    printOutput(to_string(t + a)); // Output the final result
    return 0;
}

