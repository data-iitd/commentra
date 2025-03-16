#include <bits/stdc++.h>
using namespace std;

// Function to read an integer
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a map of integers
map<int, int> MI() {
    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[i] = x;
    }
    return m;
}

// Function to read a list of integers
vector<int> LI() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Reading N, A, and B
    int N, A, B;
    cin >> N >> A >> B;
    
    // Initializing the result variable
    int ans = 0;
    
    // Calculating the number of complete cycles of A + B within N
    int rep = N / (A + B);
    
    // Updating the result with the number of complete cycles multiplied by A
    ans += rep * A;
    
    // Calculating the remaining days after the complete cycles
    int res = N - rep * (A + B);
    
    // Updating the result with the minimum of the remaining days and A
    ans += min(res, A);
    
    // Printing the final result
    cout << ans << endl;
}

