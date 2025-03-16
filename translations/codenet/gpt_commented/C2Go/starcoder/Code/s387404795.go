package main

import (
    "fmt"
    "strings"
)

func main() {
    // Declare character arrays for input strings and temporary storage
    str := make([]byte, 201)
    tmp := make([]byte, 101)
    p := make([]byte, 101)
    
    // Declare integer variables for string lengths and loop control
    slen, plen := 0, 0
    i, j, flag := 0, 0, 0
    
    // Read two strings from standard input
    fmt.Scanf("%s %s", &str, &p)
    
    // Copy the original string into a temporary variable and concatenate it with itself
    copy(tmp, str)
    str = append(str, tmp...)
    
    // Calculate the lengths of the concatenated string and the pattern string
    slen = len(str)
    plen = len(p)
    
    // Initialize a flag to indicate if the pattern is found
    flag = 0
    
    // Loop through the concatenated string to search for the pattern
    for i = 0; i < slen - plen; i++ {
        // Compare the substring of str with the pattern p
        if strings.Compare(string(str[i:i+plen]), string(p)) == 0 {
            flag = 1 // Set flag if a match is found
        }
    }
    
    // Output "Yes" if the pattern was found, otherwise output "No"
    if flag {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

