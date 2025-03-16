package main

import "fmt"

func main() {
    var t int // Declaring a variable to store the number of test cases
    fmt.Scan(&t) // Reading the number of test cases
    var count int = 0 // Initializing a counter to keep track of valid cases
    
    // Looping through each test case
    for t > 0 {
        var a, b, c int // Declaring variables to store the three integers
        fmt.Scan(&a, &b, &c) // Reading the three integers
        
        // Checking if at least one of the integers is equal to 1
        if (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1) {
            count++ // Incrementing the count if the condition is met
        }
        
        t-- // Decrementing the number of test cases
    }
    
    // Outputting the total count of valid cases
    fmt.Println(count)
}

