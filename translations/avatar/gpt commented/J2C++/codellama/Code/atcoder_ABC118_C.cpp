#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    int n;
    cin >> n;
    
    // Read the number of integers to be processed
    vector<int> a;
    
    // If there is only one integer, print it and exit
    if (n == 1) {
        int x;
        cin >> x;
        cout << x << endl;
        return 0;
    }
    
    // Read n integers from input and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    // Sort the ArrayList in ascending order
    sort(a.begin(), a.end());
    
    // If the largest number is 0, print 0 and exit
    if (a[a.size() - 1] == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Initialize the answer variable
    int ans = 0;
    
    // Loop until the ArrayList is reduced to one element
    while (true) {
        // If only one element remains, set it as the answer and break the loop
        if (a.size() == 1) {
            ans = a[0];
            break;
        }
        // Call the function to process the ArrayList and update it
        a = func(a);
    }
    
    // Print the final answer
    cout << ans << endl;
    return 0;
}

// Function to process the ArrayList and return a modified version
vector<int> func(vector<int> A) {
    // Create a copy of the input ArrayList
    vector<int> a = A;
    
    // Initialize a variable to store the minimum value
    int min = 0;
    
    // Iterate through the ArrayList
    for (int i = 0; i < a.size(); i++) {
        // If the current element is 0, remove it from the list
        if (a[i] == 0) {
            a.erase(a.begin() + i);
            i--; // Adjust index after removal
        } else {
            // If min is not zero, update the current element
            if (min != 0) {
                a[i] = a[i] % min;
                // If the updated element is 1, print 1 and exit
                if (a[i] == 1) {
                    cout << 1 << endl;
                    return a;
                }
            } else {
                // Set min to the current element if min is still zero
                min = a[i];
            }
        }
    }
    
    // Sort the modified ArrayList before returning
    sort(a.begin(), a.end());
    return a;
}

