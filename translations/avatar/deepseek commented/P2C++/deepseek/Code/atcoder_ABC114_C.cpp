#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Define a function named `aaa` that takes an argument `n`
int aaa(int N, string n) {
    // Check if the integer value of `n` is greater than N. If it is, return 0
    if (stoi(n) > N) {
        return 0;
    }
    
    // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
    unordered_set<char> digits(n.begin(), n.end());
    int ans = (digits == unordered_set<char>{'7', '5', '3'}) ? 1 : 0;
    
    // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
    for (char i : "753") {
        ans += aaa(N, n + i);
    }
    
    // Return the value of `ans`
    return ans;
}

int main() {
    int N;
    // Take an integer input N
    cin >> N;
    
    // Call the function `aaa` with the initial argument '0' and print the result
    cout << aaa(N, "0") << endl;
    
    return 0;
}

