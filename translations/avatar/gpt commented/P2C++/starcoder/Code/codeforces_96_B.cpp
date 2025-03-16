#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate numbers composed of 4s and 7s
void gen(int number, int four, int seven, vector<int> &l, int limit) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > limit) {
        return;
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the list
    if (number > 0 && four == seven) {
        l.push_back(number);
    }
    // Recursively generate the next number by adding a 4
    gen(number * 10 + 4, four + 1, seven, l, limit);
    // Recursively generate the next number by adding a 7
    gen(number * 10 + 7, four, seven + 1, l, limit);
}

// Main function to execute the number generation and find the answer
int main() {
    // Start the generation process with initial values
    vector<int> l;
    gen(0, 0, 0, l, 10000000000);
    // Sort the list of generated numbers
    sort(l.begin(), l.end());
    // Read an integer input from the user
    int n;
    cin >> n;
    int ans = 0;
    // Iterate through the sorted list to find the smallest number greater than or equal to n
    for (int val : l) {
        if (val >= n) {
            ans = val;
            break;
        }
    }
    // Print the result
    cout << ans << endl;
    return 0;
}

