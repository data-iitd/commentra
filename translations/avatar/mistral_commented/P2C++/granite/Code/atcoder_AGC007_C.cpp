
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function definition: main function takes three arguments N, d, and x
long long main(int N, int d, int x) {
    // Initializing the result variable to 0
    long long ret = 0;

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N--;
    }

    // Returning the final result
    return ret;
}

// Function to read input from standard input in buffer
vector<int> read() {
    // Initializing the vector to store the input
    vector<int> v;

    // Reading input from standard input and storing it in the vector
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // Returning the vector containing the input
    return v;
}

// Function to read a single line from standard input in buffer
string readline() {
    // Initializing the string to store the input
    string s;

    // Reading a single line from standard input and storing it in the string
    getline(cin, s);

    // Returning the string containing the input
    return s;
}

// Function to read multiple lines from standard input in buffer
vector<string> readlines() {
    // Initializing the vector to store the input
    vector<string> v;

    // Reading multiple lines from standard input and storing them in the vector
    string line;
    while (getline(cin, line)) {
        v.push_back(line);
    }

    // Returning the vector containing the input
    return v;
}

// Main function to execute the program
int main() {
    // Reading input from standard input in buffer
    vector<int> input = read();

    // Extracting the values of N, d, and x from the input vector
    int N = input[0];
    int d = input[1];
    int x = input[2];

    // Calling the main function from the Python code and printing the result
    cout << main(N, d, x) << endl;

    // Returning 0 to indicate successful execution
    return 0;
}

// Comment "