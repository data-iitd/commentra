#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Function to read input from standard input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to count occurrences of numbers
map<int, int> count(string s) {
    map<int, int> m;
    istringstream ss(s);
    int n;
    while (ss >> n) {
        m[n]++;
    }
    return m;
}

// Function to calculate the result
int calculate(map<int, int> m) {
    int c = 0;
    for (auto i : m) {
        if (i.first == 0) {
            c += i.second * (i.second - 1);
        } else if (m.find(-i.first) != m.end()) {
            c += i.second * m[-i.first];
        }
    }
    return c;
}

// Main function
int main() {
    // Read the number of test cases
    int n;
    cin >> n;

    // Initialize a Counter object 'w' to store the occurrences of numbers
    map<int, int> w;

    // Read the input string
    string s = input();

    // Store the occurrences of numbers in the Counter 'w'
    w = count(s);

    // Calculate the result
    int c = calculate(w);

    // Print the result divided by 2
    cout << c / 2 << endl;

    return 0;
}

