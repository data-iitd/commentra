#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

// Function to read a single integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers from input and return them as a map
vector<int> MI() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}

// Function to read multiple integers from input and return them as a list
vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> numbers;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

void main() {
    // Define the modulo constant
    const long long mod = 1000000007;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    vector<int> inputs = MI();
    int N = inputs[0];
    int A = inputs[1];
    int B = inputs[2];
    
    // Initialize the answer variable
    long long ans = 0;
    
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

