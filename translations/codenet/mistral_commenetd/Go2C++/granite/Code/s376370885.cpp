
// by syu
#include <bits/stdc++.h>
using namespace std;

// Define a custom scanner class that wraps istream
class Scanner {
public:
    Scanner(istream& in) : in(&in) {} // Initialize the scanner with the given istream
    int Int() { // Parse an integer from the current scanner data
        int x; *in >> x; return x; // Read an integer from the input stream and return it
    }
private:
    istream* in; // Pointer to the input stream
};

// Define a global Scanner instance for reading input data
Scanner in(cin);

// Print a line to the console with the given arguments
void Pln(vector<string> s) { // Overloaded function to print a vector of strings
    copy(s.begin(), s.end(), ostream_iterator<string>(cout, " ")); // Print the strings separated by a space
    cout << endl; // Print a new line
}
void Pln(string s) { // Overloaded function to print a single string
    cout << s << endl; // Print the string and a new line
}
void Pln(int x) { // Overloaded function to print an integer
    cout << x << endl; // Print the integer and a new line
}

// Entry point of the program
int main() {
    ios_base::sync_with_stdio(false); // Disable C++ I/O syncing with C I/O
    cin.tie(nullptr); // Disable C++ stream buffering for cin
    // Read two integers n and k from standard input
    int n, k; cin >> n >> k;
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        Pln(0);
    } else {
        // If n is not divisible by k, print 1 to the console
        Pln(1);
    }
}


