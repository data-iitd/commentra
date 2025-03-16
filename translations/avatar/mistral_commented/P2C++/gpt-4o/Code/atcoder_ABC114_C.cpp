#include <iostream>
#include <set>
#include <string>

using namespace std;

int N; // Global variable to store the input value N

int aaa(string n) { // Function definition for function `aaa` that takes a string argument `n`
    int num = stoi(n); // Convert string `n` to integer
    if (num > N) { // Check if the input integer `n` is greater than `N`
        return 0; // If it is, return 0
    }

    // Create a set from the characters of the string representation of the integer `n`
    set<char> digits(n.begin(), n.end());
    int ans = (digits == set<char>{'7', '5', '3'}) ? 1 : 0; // Assign a value of 1 to `ans` if the set of characters is equal to the set {'7', '5', '3'}; otherwise, assign it a value of 0

    for (char i : "753") { // Iterate through each character in the string "753"
        ans += aaa(n + i); // Call the function recursively with the argument `n + i` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() {
    cin >> N; // User inputs an integer value `N`
    cout << aaa("0") << endl; // Call the function with argument "0" and print the result
    return 0;
}

// <END-OF-CODE>
