
#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;

// Define a function named `aaa` that takes an argument `n`
int aaa(string n) {
    // Check if the integer value of `n` is greater than N. If it is, return 0
    if (stoi(n) > N) {
        return 0;
    }
    
    // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
    int ans = (set<char>(n.begin(), n.end()) == set<char>({'7', '5', '3'})) ? 1 : 0;
    
    // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
    for (char i : "753") {
        ans += aaa(n + i);
    }
    
    // Return the value of `ans`
    return ans;
}

// Call the function `aaa` with the initial argument '0' and print the result
int main() {
    cin >> N;
    cout << aaa("0") << endl;
    return 0;
}

