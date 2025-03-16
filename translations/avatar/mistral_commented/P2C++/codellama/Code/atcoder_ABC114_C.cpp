
#include <iostream>
#include <string>
#include <set>

using namespace std;

int N; // Global variable `N`

int aaa(string n) { // Function definition for function `aaa` that takes a string argument `n`
    if (stoi(n) > N) { // Check if the input string `n` is greater than `N`
        return 0; // If it is, return 0
    }

    int ans = 1; // Assign a value of 1 to `ans`

    for (char i : "753") { // Iterate through each character in the string "753"
        ans += aaa(n + i); // Call the function recursively with the argument `n + i` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() { // Function definition for function `main`
    cin >> N; // User inputs an integer value `N`

    cout << aaa("0") << endl; // Call the function with argument "0" and print the result

    return 0; // Return 0
}

