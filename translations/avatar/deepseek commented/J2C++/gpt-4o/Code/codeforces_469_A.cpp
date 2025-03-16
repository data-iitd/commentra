#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Total number of levels
    cin >> n;
    
    int levels; // Number of levels the first user has completed
    cin >> levels;
    
    vector<int> arr(levels); // Vector to store completed levels
    for (int i = 0; i < levels; i++) {
        cin >> arr[i]; // Read the levels completed by the first user
    }
    
    int level2; // Number of levels the second user has completed
    cin >> level2;
    
    int level3 = levels + level2; // Total number of levels completed by both users
    vector<int> arr2(level3); // Vector to store all levels completed by both users
    
    // Copy levels from arr to arr2
    for (int i = 0; i < arr.size(); i++) {
        arr2[i] = arr[i];
    }
    
    // Read additional levels for arr2
    for (int i = arr.size(); i < level3; i++) {
        cin >> arr2[i];
    }
    
    vector<int> arr3(n); // Vector to generate a sequence of numbers from 1 to n
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1; // Fill arr3 with numbers from 1 to n
    }
    
    int count = 0; // Count to track the number of levels completed
    // Check if all numbers from 1 to n are present in arr2
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < arr2.size(); x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break; // Break the inner loop if a match is found
            }
        }
    }
    
    // Print the result based on whether all levels were completed
    if (count == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
