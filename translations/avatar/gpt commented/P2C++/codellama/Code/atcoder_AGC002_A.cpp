#include <iostream>
using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string S() {
    string s;
    getline(cin, s);
    return s.substr(0, s.find_last_not_of(" \n\r\t") + 1);
}

// Function to read an integer from standard input
int I() {
    int n;
    cin >> n;
    return n;
}

// Function to read a list of integers from standard input
vector<int> LI() {
    string s = S();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        v.push_back(s[i] - '0');
    }
    return v;
}

// Function to read a list of strings from standard input
vector<string> LS() {
    string s = S();
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        int j = i + 1;
        while (j < s.size() && s[j] != ' ') j++;
        v.push_back(s.substr(i, j - i));
        i = j;
    }
    return v;
}

// Read two integers from input
int a, b;
cin >> a >> b;

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

