
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Create a function to apply the logic to the vector
vector<int> func(vector<int> A) {
    vector<int> a = A; // Create a copy of the vector to modify it without affecting the original one
    int min = 0;

    // Iterate through the vector and apply the logic to each integer
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            a.erase(a.begin() + i);
            i--;
        } else {
            if (min != 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min;
                if (a[i] == 1) { // If the result is 1, print 1 and exit the program
                    cout << 1 << endl;
                    exit(0);
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a[i];
            }
        }
    }

    // Sort the vector in ascending order and return it
    sort(a.begin(), a.end());
    return a;
}

// Create a function to read the input from the console
vector<int> readInput() {
    int n; // Declare a variable to store the number of integers
    cin >> n; // Read the number of integers from the console

    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        int x; // Declare a variable to store the only integer
        cin >> x; // Read the only integer from the console
        cout << x << endl; // Print the only integer
        exit(0); // Exit the program
    }

    // Initialize a vector to store the integers
    vector<int> a;

    // Read the rest of the integers and add them to the vector
    for (int i = 0; i < n; i++) {
        int x; // Declare a variable to store the current integer
        cin >> x; // Read the current integer from the console
        a.push_back(x); // Add the current integer to the vector
    }

    // Check if the last integer in the vector is 0, if so, print 0 and exit the program
    if (a[a.size() - 1] == 0) {
        cout << 0 << endl; // Print 0
        exit(0); // Exit the program
    }

    // Return the vector
    return a;
}

// Create a function to print the answer
void printAnswer(int ans) {
    cout << ans << endl; // Print the answer
}

// Create a function to end the program
void endProgram() {
    cout << "