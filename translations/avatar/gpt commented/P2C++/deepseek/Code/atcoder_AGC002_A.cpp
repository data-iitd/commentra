#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <map>
#include <set>

using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string S() {
    string line;
    getline(cin, line);
    return line.erase(line.find_last_not_of(" \n\r\t") + 1);
}

// Function to read an integer from standard input
int I() {
    int num;
    cin >> num;
    cin.ignore(); // To ignore the newline character after the integer
    return num;
}

// Function to read a list of integers from standard input
vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> numbers;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Function to read a list of strings from standard input
vector<string> LS() {
    string line;
    getline(cin, line);
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    // Read two integers from input
    vector<int> input = LI();
    int a = input[0];
    int b = input[1];

    // Check if the first integer 'a' is positive
    if (a > 0) {
        cout << "Positive" << endl;  // Output 'Positive' if 'a' is greater than 0
    } else if (a <= 0 && b >= 0) {
        cout << "Zero" << endl;  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
    } else {
        // If 'a' is negative and 'b' is also negative
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;  // Output 'Negative' if the sum of 'a' and 'b' is even
        } else {
            cout << "Positive" << endl;  // Output 'Positive' if the sum of 'a' and 'b' is odd
        }
    }

    return 0;
}
