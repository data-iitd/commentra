#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Function to check if a string contains only '7', '5', and '3'
bool containsOnly753(const string& s) {
    unordered_set<char> digits = {'7', '5', '3'};
    for (char c : s) {
        if (digits.find(c) == digits.end()) {
            return false;
        }
    }
    return true;
}

// Recursive function to count numbers with digits '7', '5', and '3'
int aaa(int N, string n) {
    // Convert the string to an integer
    int num = stoi(n);

    // Check if the integer value of 'n' exceeds the limit N
    if (num > N) {
        return 0; // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    int ans = containsOnly753(n) ? 1 : 0;

    // Iterate over each character in the string '753'
    for (char i : {'7', '5', '3'}) {
        // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(N, n + i);
    }

    // Return the accumulated answer
    return ans;
}

int main() {
    // Read an integer input from the user
    int N;
    cin >> N;

    // Print the result of calling 'aaa' with the initial value '0'
    cout << aaa(N, "0") << endl;

    return 0;
}
