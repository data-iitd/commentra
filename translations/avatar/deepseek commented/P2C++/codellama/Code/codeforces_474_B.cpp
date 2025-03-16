
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> L;
    // Initialize an empty vector L to store the results.
    string input;
    // Take the first input from the user.
    int r = 1;
    // Initialize the variable r to 1.
    for (string k : input.split()) {
        // Split the first input into a list of strings and iterate over each string.
        L.insert(L.end(), r, stoi(k));
        // Multiply the string '1' by the integer value of the string and append the result to the vector L.
        r++;
        // Increment r by 1 for the next iteration.
    }
    input = "";
    // Take the second input from the user.
    for (string j : input.split()) {
        // Split the second input into a list of strings and iterate over each string.
        cout << L[stoi(j) - 1] << endl;
        // For each string, print the element at the index specified by the integer value of the string minus one from the vector L.
    }
    return 0;
}

