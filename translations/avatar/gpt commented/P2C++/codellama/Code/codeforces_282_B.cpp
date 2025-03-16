#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the first line of input which indicates the number of iterations
    int firstline;
    cin >> firstline;

    // Initialize total to keep track of the accumulated value
    int total = 0;

    // Create an empty list to store the memory of actions taken
    vector<string> memory;

    // Loop through the range defined by firstline
    for (int x = 0; x < firstline; x++) {
        // Read two integers A and G from input, separated by space
        int A, G;
        cin >> A >> G;

        // Check if adding A to total does not exceed the limit of 500
        if (total + A <= 500) {
            // If within limit, add A to total
            total += A;
            // Record the action "A" in memory
            memory.push_back("A");
        } else {
            // If limit exceeded, subtract G from total
            total -= G;
            // Record the action "G" in memory
            memory.push_back("G");
        }
    }

    // Print the sequence of actions taken as a single string
    for (int i = 0; i < memory.size(); i++) {
        cout << memory[i];
    }

    // End with comment "