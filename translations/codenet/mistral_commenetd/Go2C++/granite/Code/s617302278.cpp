

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
#include <exception>

using namespace std;

// Function to read a line text from stdin and return its string
string NextLine() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers vector
vector<int> NextIntsLine() {
    string s = NextLine();
    stringstream ss(s);
    vector<int> v;
    int n;
    while (ss >> n) {
        v.push_back(n);
        if (ss.peek() =='') {
            ss.ignore();
        }
    }
    return v;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes vector
vector<char> NextRunesLine() {
    string s = NextLine();
    vector<char> v;
    for (char c : s) {
        v.push_back(c);
    }
    return v;
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Max(vector<int> v) {
    int m = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (m < v[i]) {
            m = v[i];
        }
    }
    return m;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Min(vector<int> v) {
    int m = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (m > v[i]) {
            m = v[i];
        }
    }
    return m;
}

// Function to calculate integer power
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw runtime_error("[argument error]: PowInt does not accept negative integers");
    }
    return pow(a, e);
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
    return abs(a);
}

// Function to delete an element from a vector
vector<int> DeleteElement(vector<int> v, int i) {
    if (i < 0 || i >= v.size()) {
        throw runtime_error("[index error]");
    }
    vector<int> n;
    for (int j = 0; j < v.size(); j++) {
        if (j!= i) {
            n.push_back(v[j]);
        }
    }
    return n;
}

// Function to concatenate two vectors
vector<char> Concat(vector<char> s, vector<char> t) {
    vector<char> n;
    for (char c : s) {
        n.push_back(c);
    }
    for (char c : t) {
        n.push_back(c);
    }
    return n;
}

// Function to sort a vector using sort algorithm
//sort(v.begin(), v.end());
//sort(v.rbegin(), v.rend());

// Function to copy elements from one vector to another
//vector<int> a = {0, 1, 2};
//vector<int> b(a.size());
//copy(a.begin(), a.end(), b.begin());

// Variable declaration and initialization
int x;

int main() {
    // Reading integers from stdin as a line text
    vector<int> tmp = NextIntsLine();
    // Assigning the first integer to variable x
    x = tmp[0];
    // Initializing sum variable as zero
    int sum = 0;
    // Initializing index variable as one
    int i = 1;
    // Looping until the sum is greater than or equal to x
    while (true) {
        // Adding current index to sum
        sum += i;
        // Checking if sum is greater than or equal to x
        if (sum >= x) {
            // Breaking the loop
            break;
        }
        // Incrementing index
        i++;
    }
    // Printing the index
    cout << i << endl;
    return 0;
}

