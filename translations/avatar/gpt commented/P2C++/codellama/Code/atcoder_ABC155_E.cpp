#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Define the available input methods
const string input_methods[] = {"clipboard", "file", "key"};
int using_method = 0;  // Index to select the input method
string input_method = input_methods[using_method];  // Select the input method based on the index

// Define a lambda function for reading multiple integers from input
auto IN = []{
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    vector<int> v;
    while (ss >> x) {
        v.emplace_back(x);
    }
    return v;
};
const int mod = 1000000007;  // Define a modulus value for calculations

int main_b() {
    // Read input string
    string s;
    getline(cin, s);
    int pp = 0;  // Initialize the total score
    int na = 0;  // Initialize carry-over value

    // Process the string in reverse order
    for (int i = s.size() - 1; i >= 0; i--) {
        int cc = na + s[i] - '0';  // Calculate the current value with carry-over
        na = 0;  // Reset carry-over for the next iteration

        // Determine how to update the total score based on the current value
        if (cc <= 4) {
            pp += cc;  // If the value is 4 or less, add it directly to the score
        } else {
            na = 1;  // Set carry-over if the value exceeds 4
            if (i == 0) {
                pp += 1;  // If it's the last digit, add 1 to the score
            }
            pp += 10 - cc;  // Add the difference to the score
        }
    }
    cout << pp << endl;  // Output the final score
    return 0;
}

int main() {
    // Read input string
    string s;
    getline(cin, s);
    int pmin = 1000;  // Initialize minimum score for positive values
    int mmin = 0;  // Initialize minimum score for negative values
    s = "0" + s;  // Prepend '0' to the input string for easier processing

    // Process the string in reverse order
    for (int i = s.size() - 1; i >= 0; i--) {
        int v = s[i] - '0';  // Convert character to integer
        // Calculate new minimum scores based on current digit
        int npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        int nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;  // Update positive minimum score
        mmin = nmmin;  // Update negative minimum score
    }
    return min(pmin, mmin);  // Return the minimum score between positive and negative
}

// 