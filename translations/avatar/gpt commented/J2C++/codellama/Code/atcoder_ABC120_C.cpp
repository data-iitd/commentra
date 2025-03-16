
#include <iostream> 
#include <string> 
#include <stack> 
using namespace std; 

int main() { 
    // Set up input and output streams
    string x; 
    cin >> x; 
    stack<char> s; 
    int c = 0; // Counter for pairs of '0' and '1'
    
    // Iterate through each character in the input string
    for (int i = 0; i < x.length(); i++) { 
        // Push the current character onto the stack
        s.push(x[i]); 
        
        // Process the stack while there are at least two characters
        while (s.size() > 1) { 
            char p = s.top(); // Pop the top character
            s.pop(); 
            char q = s.top(); // Pop the next character
            s.pop(); 
            
            // Check if the characters form a pair of '0' and '1'
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) { 
                c++; // Increment the counter for valid pairs
                continue; // Continue to check for more pairs
            } else { 
                // If not a valid pair, push the characters back onto the stack
                s.push(q); 
                s.push(p); 
                break; // Exit the while loop
            } 
        } 
    } 
    // Output the result, which is twice the count of pairs found
    cout << c * 2 << endl; 
    return 0; 
} 

