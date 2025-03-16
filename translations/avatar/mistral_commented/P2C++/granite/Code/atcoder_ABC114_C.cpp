

#include <iostream>
#include <set>
#include <string>

using namespace std;

int N; // Global variable `N`

int aaa(string n) { // Function definition for function `aaa` that takes a string argument `n`
    if (stoi(n) > N) { // Check if the integer value of the string `n` is greater than `N`
        return 0; // If it is, return 0
    }

    int ans = 1; // Initialize `ans` to 1

    if (set<char>(n.begin(), n.end())!= set<char>({'7', '5', '3'})) { // Check if the set of characters in the string `n` is equal to the set `{'7', '5', '3'}`
        ans = 0; // If it is not, assign `ans` a value of 0
    }

    for (char i : {'7', '5', '3'}) { // Iterate through each character in the string `'753'`
        ans += aaa(n + string(1, i)); // Call the function recursively with the argument `n + string(1, i)` and add the result to `ans`
    }

    return ans; // Return the value of `ans`
}

int main() {
    cin >> N; // User inputs an integer value `N`
    cout << aaa("0") << endl; // Call the function with argument `"0"` and print the result
    return 0; // Return 0
}

