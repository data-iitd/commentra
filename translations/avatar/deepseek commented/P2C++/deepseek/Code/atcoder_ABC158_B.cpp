#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a map of integers
vector<int> MI() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

// Function to read a list of integers
vector<int> LI() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

// Main function
void main() {
    const int mod = 1000000007;  // Modulo value
    vector<int> NAB = MI();  // Reading N, A, and B
    int N = NAB[0], A = NAB[1], B = NAB[2];
    int ans = 0;  // Initializing the result variable
    
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

