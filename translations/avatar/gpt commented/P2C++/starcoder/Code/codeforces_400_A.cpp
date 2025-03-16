#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input and convert it to a tuple of integers
tuple<int, int> value() {
    return make_tuple(stoi(input()), stoi(input()));
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
tuple<int, int> values() {
    return make_tuple(stoi(cin.rdbuf()), stoi(cin.rdbuf()));
}

// Function to read a single line of input and return a list of integers
vector<int> inlst() {
    return vector<int>(istream_iterator<int>(cin), istream_iterator<int>());
}

// Function to read a single line of input from stdin and return a list of integers
vector<int> inlsts() {
    return vector<int>(istream_iterator<int>(cin.rdbuf()), istream_iterator<int>());
}

// Function to read a single integer from input
int inp() {
    return stoi(input());
}

// Function to read a single integer from stdin
int inps() {
    return stoi(cin.rdbuf());
}

// Function to read a single line of input and return it as a string
string instr() {
    return string(istream_iterator<char>(cin), istream_iterator<char>());
}

// Function to read a single line of input and return it as a list of strings
vector<string> stlst() {
    return vector<string>(istream_iterator<string>(cin), istream_iterator<string>());
}

// Helper function to determine if a specific arrangement is possible
bool help(int a, int b, vector<int> l) {
    vector<vector<int>> tot;
    // Create sublists of length 'a' from the list 'l'
    for (int i = 0; i < b; i++) {
        tot.push_back(vector<int>(l.begin() + i * a, l.begin() + i * a + a));
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (auto i : tot) {
        if (accumulate(i.begin(), i.end(), 0) == b) {
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
    for (char i : x) {
        if (i == 'O') {
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
    for (auto a, b : tot) {
        cout << a << "x" << b << " ";
    }
    cout << endl;  // Print a newline at the end
}

// Entry point of the program
int main() {
    // Read the number of test cases and solve each case
    for (int i = 0; i < inp(); i++) {
        solve();
    }
    return 0;
}

