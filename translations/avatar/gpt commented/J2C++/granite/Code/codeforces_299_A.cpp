
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a vector to store the input values
    vector<int> a;
    
    // Read the number of elements in the array
    int n;
    cin >> n;
    
    // Loop to read n integers from the user and store them in the vector
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        a.push_back(value);
    }
    
    // Sort the vector in ascending order
    sort(a.begin(), a.end());
    
    // Store the minimum value from the sorted vector
    int min = a[0];
    
    // Check if all elements in the vector are divisible by the minimum value
    for (int value : a) {
        if (value % min!= 0) {
            // If any element is not divisible, print -1 and exit
            cout << -1 << endl;
            return 0;
        }
    }
    
    // If all elements are divisible, print the minimum value
    cout << min << endl;
    
    return 0;
}
