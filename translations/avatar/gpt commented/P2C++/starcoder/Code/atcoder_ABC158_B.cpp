#include <bits/stdc++.h>

using namespace std;

// Function to read a single integer from input
int I() {
    return scanf("%d", &n);
}

// Function to read multiple integers from input and return them as a map
map<int, int> MI() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[i] = x;
    }
    return m;
}

// Function to read multiple integers from input and return them as a list
vector<int> LI() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

int main() {
    // Define the modulo constant
    const int mod = 1000000007;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    cin >> N >> A >> B;
    
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
}

// 