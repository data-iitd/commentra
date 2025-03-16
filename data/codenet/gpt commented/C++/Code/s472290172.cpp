#include <iostream>                                                                                                                               
#include <map>                                                                                                                                    
using namespace std;                                                                                                                              

int main() {                                                                                                                                      
    // Declare a string variable to hold the input
    string str;                                                                                                                                   
    // Read input string from the user
    cin >> str;                                                                                                                                   
    
    // Initialize variables to track the maximum length of valid characters and the current count
    int max = 0, cnt = 0;                                                                                                                         
    
    // Iterate through each character in the input string
    for (auto sc : str) {                                                                                                                         
        // Check if the character is one of the valid DNA bases
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {                                                                                   
            // Increment the count for consecutive valid characters
            cnt++;                                                                                                                                
        } else {                                                                                                                                  
            // Reset the count if an invalid character is encountered
            cnt = 0;                                                                                                                              
        }                                                                                                                                         
        // Update the maximum length if the current count exceeds the previous maximum
        max = max < cnt ? cnt : max;                                                                                                              
    }                                                                                                                                             
                                                                                                                                                  
    // Output the maximum length of consecutive valid characters found
    cout << max << endl;                                                                                                                          
}    
