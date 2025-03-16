#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function to apply the logic to the vector
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

int main() {
    // Initialize a vector to store the integers
    vector<int> a;

    // Read the first integer from the input
    int n;
    cin >> n;

    // Check if the input is 1, if so, read the only integer and print it and exit the program
    if (n == 1) {
        int num;
        cin >> num;
        cout << num << endl; // Print the only integer
        return 0; // Exit the program
    }

    // Read the rest of the integers and add them to the vector
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    // Sort the vector in ascending order
    sort(a.begin(), a.end());

    // Check if the last integer in the vector is 0, if so, print 0 and exit the program
    if (a[a.size() - 1] == 0) {
        cout << 0 << endl; // Print 0
        return 0; // Exit the program
    }

    // Use a while loop to keep applying the function to the vector until it contains only one element
    while (true) {
        if (a.size() == 1) {
            cout << a[0] << endl; // Assign the only remaining integer to the answer variable and print it
            break; // Exit the loop
        }
        a = func(a); // Apply the function to the vector and assign the result back to it
    }

    return 0;
}

