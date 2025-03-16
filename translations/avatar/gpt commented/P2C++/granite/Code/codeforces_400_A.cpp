
#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input and convert it to a tuple of integers
tuple<int, int, int> value() {
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
tuple<int, int, int> values() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    return make_tuple(a, b, c);
}

// Function to read a single line of input and return a list of integers
vector<int> inlst() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a single line of input from stdin and return a list of integers
vector<int> inlsts() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return a;
}

// Function to read a single integer from input
int inp() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single integer from stdin
int inps() {
    int a;
    scanf("%d", &a);
    return a;
}

// Function to read a single line of input and return it as a string
string instr() {
    string a;
    cin >> a;
    return a;
}

// Function to read a single line of input and return it as a list of strings
vector<string> stlst() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Helper function to determine if a specific arrangement is possible
bool help(int a, int b, vector<int> l) {
    vector<vector<int>> tot;
    // Create sublists of length 'a' from the list 'l'
    for (int i = 0; i < b; i++) {
        tot.push_back(vector<int>(l.begin() + i * a, l.begin() + i * a + a));
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    vector<pair<int, int>> tot;
    string x = instr();  // Read the input string
    vector<int> s;
    
    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (char c : x) {
        if (c == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                tot.push_back(make_pair(12 / i, i));  // Store valid arrangements as pairs
            }
        }
    }
    
    // Print the number of valid arrangements
    cout << tot.size() << " ";
    
    // Print each valid arrangement in sorted order
    sort(tot.begin(), tot.end());
    for (auto p : tot) {
        cout << p.first << "x" << p.second << " ";
    }
    cout << endl;  // Print a newline at the end
}

// Entry point of the program
int main() {
    // Read the number of test cases and solve each case
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

Translate the above Python code to Java and end with comment "