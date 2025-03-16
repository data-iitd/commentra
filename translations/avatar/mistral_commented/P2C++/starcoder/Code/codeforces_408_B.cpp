
#include <bits/stdc++.h>
using namespace std;

// Define helper functions
template<typename T>
void hpop(priority_queue<T>& heap) { heap.pop(); }
template<typename T>
void hpush(priority_queue<T>& heap, T item) { heap.push(item); }

// Function to find the solution
void solution() {
    // Read the first line and count the number of occurrences of each color
    string line;
    cin >> line;
    unordered_map<char, int> bought_count;
    for (char c : line) {
        bought_count[c]++;
    }

    // Read the second line and count the number of occurrences of each color
    cin >> line;
    unordered_map<char, int> made_count;
    for (char c : line) {
        made_count[c]++;
    }

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in made_cout
    for (auto it = made_count.begin(); it!= made_count.end(); it++) {
        // Check if the color is present in bought_count
        if (bought_count.find(it->first) == bought_count.end()) {
            // If not, print -1 and exit the function
            cout << -1 << endl;
            return;
        }

        // Update the result by adding the minimum of bought and made counts
        res += min(bought_count[it->first], it->second);
    }

    // Print the result
    cout << res << endl;
}

// Main function to run the solution function for multiple test cases
int main() {
    // Read the number of test cases
    int t;
    cin >> t;

    // Run the solution function for each test case
    for (int i = 0; i < t; i++) {
        solution();
    }
}

