#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Set up input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin.exceptions(cin.failbit); 
    
    // Read four integers from input
    int a, b, c, d; 
    cin >> a >> b >> c >> d; 
    
    // Check conditions to determine the output
    if (c > b) { 
        // If c is greater than b, output 0
        cout << 0 << endl; 
    } else if (a > d) { 
        // If a is greater than d, output 0
        cout << 0 << endl; 
    } else if (a < c) { 
        // If a is less than c, calculate and output the difference
        cout << min(b, d) - c << endl; 
    } else { 
        // Create a list to hold the four integers
        list<int> l; 
        l.push_back(a); 
        l.push_back(b); 
        l.push_back(c); 
        l.push_back(d); 
        
        // Sort the list to find the second largest and third largest values
        l.sort(); 
        
        // Output the difference between the second largest and third largest values
        cout << l.front() - l.back() << endl; 
    } 
} 

