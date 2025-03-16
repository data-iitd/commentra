
#include <iostream>
#include <cstring>

int main() {
    // Declare character arrays for input strings and temporary storage
    char str[201], tmp[101];
    char p[101];
    
    // Declare integer variables for string lengths and loop control
    int slen, plen;
    int i, j, flag;
    
    // Read two strings from standard input
    std::cin >> str >> p;
    
    // Copy the original string into a temporary variable and concatenate it with itself
    strcpy(tmp, str);
    strcat(str, tmp);
    
    // Calculate the lengths of the concatenated string and the pattern string
    slen = strlen(str);
    plen = strlen(p);
    
    // Initialize a flag to indicate if the pattern is found
    flag = 0;
    
    // Loop through the concatenated string to search for the pattern
    for (i = 0; i < slen - plen; i++) {
        // Compare the substring of str with the pattern p
        if (strncmp(&str[i], p, plen) == 0) 
            flag = 1; // Set flag if a match is found
    }
    
    // Output "Yes" if the pattern was found, otherwise output "No"
    if (flag) 
        std::cout << "Yes" << std::endl;
    else 
        std::cout << "No" << std::endl;
    
    return 0; // Return success
}

