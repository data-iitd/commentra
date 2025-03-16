#include <iostream>
using namespace std;

// Function to read a single integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers from input and return them as a pair
pair<int, int> MI() {
    int a, b;
    cin >> a >> b;
    return make_pair(a, b);
}

int main() {
    // Define the modulo constant
    const int mod = 1e9 + 7;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    cin >> N >> A >> B;
    
    // Initialize the answer variable
    long long ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    long long rep = N / (A + B);
    
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

// <END-OF-CODE>
