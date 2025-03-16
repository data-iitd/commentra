#include <iostream>
#include <string>
#include <set>

using namespace std;

// Define a global variable for the limit N
int N;

// Define a recursive function 'aaa' that takes a string 'n'
int aaa(string n) {
    // Check if the integer value of 'n' exceeds the limit N
    if (stoi(n) > N) {
        return 0;  // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    set<char> digits(n.begin(), n.end());
    int ans = (digits.size() == 3 && digits.count('7') && digits.count('5') && digits.count('3')) ? 1 : 0;

    // Iterate over each character in the string '753'
    for (char i : "753") {
        // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(n + i);
    }

    // Return the accumulated answer
    return ans;
}

int main() {
    // Read an integer input from the user
    cin >> N;

    // Print the result of calling 'aaa' with the initial value '0'
    cout << aaa("0") << endl;

    return 0;
}

// <END-OF-CODE>
