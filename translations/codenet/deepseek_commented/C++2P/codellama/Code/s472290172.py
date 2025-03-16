#include <iostream>                                                                                                                               
#include <map>                                                                                                                                    
using namespace std;                                                                                                                              
                                                                                                                                                  
int main() {                                                                                                                                      
    string str;                                                                                                                                    // Read the input string from the standard input.
    cin >> str;                                                                                                                                   
                                                                                                                                                  
    int max = 0, cnt = 0;                                                                                                                         
    // Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.
                                                                                                                                                  
    for sc in str:                                                                                                                                 
        // Iterate over each character in the string.
        if sc == 'A' or sc == 'C' or sc == 'G' or sc == 'T':                                                                                      
            // Check if the character is one of 'A', 'C', 'G', or 'T'.
            cnt += 1                                                                                                                              
            // If it is, increment the cnt variable.
        else:                                                                                                                                     
            cnt = 0                                                                                                                               
            // If not, reset cnt to 0.
        max = max if max > cnt else cnt                                                                                                          
        // After each character, update max to be the maximum of max and cnt.
    print(max)                                                                                                                                   
    // Print the value of max to the standard output.
}    


