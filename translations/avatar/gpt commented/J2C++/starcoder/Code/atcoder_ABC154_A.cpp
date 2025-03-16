#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Read a line of input, split it by spaces, and store it in an array
    string str[3]; 
    cin >> str; 
    
    // Read another line of input and store it in variable 'u'
    string u; 
    cin >> u; 
    
    // Create a StringTokenizer to read the next line of input
    stringstream ss(u); 
    
    // Parse the first token as an integer and store it in variable 'a'
    int a; 
    ss >> a; 
    
    // Parse the second token as an integer and store it in variable 'b'
    int b; 
    ss >> b; 
    
    // Compare the string 'u' with the first element of the array'str'
    // Print the result based on the comparison
    cout << (u.compare(str[0]) == 0? (a - 1) + " " + b : a + " " + (b - 1)) << endl; 
    
    return 0; 
}

