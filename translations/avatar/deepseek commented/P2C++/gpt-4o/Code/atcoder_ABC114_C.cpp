#include <iostream>
#include <set>
#include <string>

using namespace std;

int N;  // Declare a global variable N

// Define a function named `aaa` that takes an argument `n`
int aaa(string n) {
    // Check if the integer value of `n` is greater than N. If it is, return 0
    if (stoi(n) > N) {
        return 0;
    }
    
    // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
    set<char> digits(n.begin(), n.end());
    int ans = (digits.size() == 3 && digits.count('7') && digits.count('5') && digits.count('3')) ? 1 : 0;
    
    // Iterate over the string "753" and recursively call the function `aaa` with `n` incremented by each digit
    for (char i : "753") {
        ans += aaa(n + i);
    }
    
    // Return the value of `ans`
    return ans;
}

int main() {
    cin >> N;  // Take an integer input N
    cout << aaa("0") << endl;  // Call the function `aaa` with the initial argument "0" and print the result
    return 0;
}

// <END-OF-CODE>
