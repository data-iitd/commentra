#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // Step 3: Create a variable to read input from the user
    int n, a, b;
    
    // Step 4: Read the values of n, a, and b
    cin >> n >> a >> b;
    
    // Step 5: Create two vectors to store the lists of integers
    unordered_set<int> list1, list2;
    
    // Step 6: Read the elements of list1 and list2 from the user
    for (int i = 0; i < a; i++) {
        int value;
        cin >> value;
        list1.insert(value);
    }
    for (int i = 0; i < b; i++) {
        int value;
        cin >> value;
        list2.insert(value);
    }
    
    // Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for (int i = 1; i <= n; i++) {
        if (list1.find(i) != list1.end()) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    
    return 0;
}

// <END-OF-CODE>
