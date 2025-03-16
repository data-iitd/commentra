#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

// Define two helper functions to read input from the standard input stream
string S() {
    string line;
    getline(cin, line);
    return line.erase(line.find_last_not_of(' ') + 1);
}

int I() {
    int num;
    cin >> num;
    cin.ignore();
    return num;
}

// Define another helper function to read a list of integers from the standard input stream
vector<int> LI() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Define another helper function to read a list of strings from the standard input stream
vector<string> LS() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> strings;
    string str;
    while (ss >> str) {
        strings.push_back(str);
    }
    return strings;
}

int main() {
    // Define two variables and initialize them with the values read from the standard input stream
    vector<int> input = LI();
    int a = input[0];
    int b = input[1];

    // Check if 'a' is positive
    if (a > 0) {
        // If it is, print the string 'Positive'
        cout << "Positive" << endl;
    }
    // If 'a' is not positive, check if 'b' is non-negative
    else if (a <= 0 && b >= 0) {
        // If it is, print the string 'Zero'
        cout << "Zero" << endl;
    }
    // If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
    else {
        // If it is, print the string 'Negative'
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;
        }
        // Otherwise, print the string 'Positive'
        else {
            cout << "Positive" << endl;
        }
    }

    return 0;
}
