#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read an input line (not used in the logic)
    cin.ignore();
    
    // Read a line of integers, split by spaces, and convert them to a list of integers
    vector<int> a;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    // Sort the list of integers in ascending order
    sort(a.begin(), a.end());
    
    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < a.size(); i++) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            cout << "YES" << endl;
            return 0;
        }
    }
    
    // If no such pair is found, return 'NO'
    cout << "NO" << endl;
    return 0;
}

