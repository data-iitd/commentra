
#####
#include <bits/stdc++.h>
using namespace std;

// Define helper functions
int hpop(priority_queue<int>& heap) { return heap.top(); }
void hpush(priority_queue<int>& heap, int item) { heap.push(item); }

#####
// Function to find the solution
#####

void solution() {
    // Read the first line and count the number of occurrences of each color
    string line;
    cin >> line;
    map<char, int> bought_count;
    for (char color : line) {
        bought_count[color]++;
    }

    // Read the second line and count the number of occurrences of each color
    cin >> line;
    map<char, int> made_cout;
    for (char color : line) {
        made_cout[color]++;
    }

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in made_cout
    for (char color : made_cout) {
        // Check if the color is present in bought_count
        if (bought_count.find(color) == bought_count.end()) {
            // If not, print -1 and exit the function
            cout << -1 << endl;
            return;
        }

        // Update the result by adding the minimum of bought and made counts
        res += min(bought_count[color], made_cout[color]);
    }

    // Print the result
    cout << res << endl;
}

#####
// Main function to run the solution function for multiple test cases
#####

int main() {
    // Read the number of test cases
    int t;
    cin >> t;

    // Run the solution function for each test case
    for (int i = 0; i < t; i++) {
        solution();
    }

    return 0;
}

Translate the above Python code to Java and end with comment "