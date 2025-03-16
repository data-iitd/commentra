
package main

import "fmt"

func main() {
    // Declare an array to hold 10 integers
    var v [10]int
    
    // Initialize a variable to hold the sum of the integers
    sum := 0
    
    // Declare a loop variable
    var i int
    
    // Prompt the user to enter 10 integers and store them in the array
    for i = 0; i < 10; i++ {
        fmt.Scan(&v[i])
    }
    
    // Calculate the sum of the integers stored in the array
    for i = 0; i < 10; i++ {
        sum += v[i]
    }
    
    // Output the calculated sum to the console
    fmt.Println(sum)
}

