

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    // Step 3: Create a Scanner object to read input from the user
    Scanner sc; 
    
    // Step 4: Read the values of n, a, and b
    int n, a, b; 
    cin >> n >> a >> b; 
    
    // Step 5: Create two ArrayList objects to store the lists of integers
    vector < int > list1; 
    vector < int > list2; 
    
    // Step 6: Read the elements of list1 and list2 from the user
    for (int i = 0; i < a; i++) { 
        int temp; 
        cin >> temp; 
        list1.push_back(temp); 
    } 
    for (int i = 0; i < b; i++) { 
        int temp; 
        cin >> temp; 
        list2.push_back(temp); 
    } 
    
    // Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for (int i = 1; i <= n; i++) { 
        if (find(list1.begin(), list1.end(), i)!= list1.end()) { 
            cout << 1 << " "; 
        } else { 
            cout << 2 << " "; 
        } 
    } 
    return 0; 
} 
