
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    Scanner sc(cin); 
    
    // Declare variables for the number of elements and sizes of the two lists
    int n, a, b; 
    
    // Read the values for n, a, and b from the input
    cin >> n >> a >> b; 
    
    // Initialize two vectors to store the elements of the two lists
    vector<int> list1; 
    vector<int> list2; 
    
    // Read 'a' integers into list1
    for (int i = 0; i < a; i++) { 
        int temp; 
        cin >> temp; 
        list1.push_back(temp); 
    } 
    
    // Read 'b' integers into list2
    for (int i = 0; i < b; i++) { 
        int temp; 
        cin >> temp; 
        list2.push_back(temp); 
    } 
    
    // Iterate from 0 to n-1 to check the presence of each index in list1
    for (int i = 0; i < n; i++) { 
        // If the current index + 1 is in list1, print 1
        if (find(list1.begin(), list1.end(), i + 1)!= list1.end()) { 
            cout << 1 << " "; 
        } else { 
            // Otherwise, print 2
            cout << 2 << " "; 
        } 
    } 
    
    // End the program
    return 0; 
}
