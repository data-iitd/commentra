
#include <iostream>
#include <cmath>

using namespace std;

// Function to read a single integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers from input and return them as a map
map<int, int> MI() {
    map<int, int> m;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        m[x]++;
    }
    return m;
}

// Function to read multiple integers from input and return them as a list
vector<int> LI() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}

int main() {
    // Define the modulo constant
    int mod = 1000000007;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N = I();
    int A = I();
    int B = I();
    
    // Initialize the answer variable
    int ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += min(res, A);
    
    // Print the final answer
    cout << ans << endl;
    
    return 0;
}

