#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input and convert it to a tuple of integers
tuple<int, int> value() {
    string s;
    cin >> s;
    int a = stoi(s.substr(0, s.find('x')));
    int b = stoi(s.substr(s.find('x') + 1));
    return make_tuple(a, b);
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
tuple<int, int> values() {
    string s = "";
    getline(cin, s);
    int a = stoi(s.substr(0, s.find('x')));
    int b = stoi(s.substr(s.find('x') + 1));
    return make_tuple(a, b);
}

// Function to read a single line of input and return a list of integers
vector<int> inlst() {
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(stoi(s));
    return v;
}

// Function to read a single line of input from stdin and return a list of integers
vector<int> inlsts() {
    string s = "";
    getline(cin, s);
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(stoi(s));
    return v;
}

// Function to read a single integer from input
int inp() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single integer from stdin
int inps() {
    string s = "";
    getline(cin, s);
    return stoi(s);
}

// Function to read a single line of input and return it as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to read a single line of input and return it as a list of strings
vector<string> stlst() {
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(s.substr(0, i));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(s);
    return v;
}

// Helper function to determine if a specific arrangement is possible
bool help(int a, int b, vector<int> l) {
    vector<vector<int>> tot;
    // Create sublists of length 'a' from the list 'l'
    for (int i = 0; i < b; i++) {
        vector<int> v;
        for (int j = 0; j < a; j++) {
            v.push_back(l[i * a + j]);
        }
        tot.push_back(v);
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (int i = 0; i < pow(2, b); i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            if (i & (1 << j)) {
                sum += tot[j][0];
            }
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    vector<tuple<int, int>> tot;
    string x = instr();  // Read the input string
    vector<int> s;
    
    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                tot.push_back(make_tuple(12 / i, i));  // Store valid arrangements as tuples
            }
        }
    }
    
    // Print the number of valid arrangements
    cout << tot.size() << " ";
    
    // Print each valid arrangement in sorted order
    sort(tot.begin(), tot.end());
    for (int i = 0; i < tot.size(); i++) {
        cout << get<0>(tot[i]) << "x" << get<1>(tot[i]) << " ";
    }
    cout << endl;
}

// Entry point of the program
int main() {
    // Read the number of test cases and solve each case
    int t = inp();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

