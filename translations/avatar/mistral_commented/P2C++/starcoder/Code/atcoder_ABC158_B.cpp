#include <bits/stdc++.h>

using namespace std;

// Function to read an integer
int I( ) {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers
vector<int> MI( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a list of integers
vector<int> LI( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to print a list of integers
void P(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Main function
int main( ) {
    // Setting the modulus value
    int mod = 1000000007;

    // Reading input values: N, A, and B
    int N, A, B;
    cin >> N >> A >> B;

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    cout << ans << endl;
}

// 