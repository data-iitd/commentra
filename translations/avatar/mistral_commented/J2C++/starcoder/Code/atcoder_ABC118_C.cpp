
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    Scanner sc;
    sc.sync_with_stdio(0);
    sc.tie(0);
    sc.exceptions(sc.failbit);
    sc.exceptions(sc.badbit);
    int n;
    // Read the first integer from the input
    n = sc.nextInt();
    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        cout << sc.nextInt() << endl; // Print the only integer
        return 0; // Exit the program
    }
    // Initialize an ArrayList to store the integers
    vector<int> a;
    // Read the rest of the integers and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        a.push_back(sc.nextInt());
    }
    // Sort the ArrayList in ascending order
    sort(a.begin(), a.end());
    // Check if the last integer in the ArrayList is 0, if so, print 0 and exit the program
    if (a[a.size() - 1] == 0) {
        cout << 0 << endl; // Print 0
        return 0; // Exit the program
    }
    // Initialize the answer variable
    int ans = 0;
    // Use a while loop to keep applying the function to the ArrayList until it contains only one element
    while (true) {
        if (a.size() == 1) {
            ans = a[0]; // Assign the only remaining integer to the answer variable
            break; // Exit the loop
        }
        a = func(a); // Apply the function to the ArrayList and assign the result back to it
    }
    // Print the answer
    cout << ans << endl;
}

// Define a private static function to apply the logic to the ArrayList
vector<int> func(vector<int> A) {
    vector<int> a = A; // Create a copy of the ArrayList to modify it without affecting the original one
    int min = 0;
    // Iterate through the ArrayList and apply the logic to each integer
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            a.erase(a.begin() + i);
            i--;
        } else {
            if (min!= 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min;
                if (a[i] == 1) { // If the result is 1, print 1 and exit the program
                    cout << 1 << endl;
                    return a;
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a[i];
            }
        }
    }
    // Sort the ArrayList in ascending order and return it
    sort(a.begin(), a.end());
    return a;
}

