
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define the modulo constant
    const int mod = 100000007;
    
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
    
    return 0;
}

