package main

import "fmt"

func main() {
    // Declare a variable to hold the input string
    var a string
    
    // Read input from the user and store it in variable 'a'
    fmt.Scan(&a)
    
    // Initialize a variable 'ans' with the default value "Good"
    var ans = "Good"
    
    // Loop through the first three characters of the string 'a'
    for i := 0; i < 3; i++ {
        // Check if the current character is the same as the next character
        if a[i] == a[i+1] {
            // If they are the same, set 'ans' to "Bad"
            ans = "Bad"
        }
    }
    
    // Print the final result stored in 'ans'
    fmt.Println(ans)
}
