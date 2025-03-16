package main

import "fmt"

const N = 2000 // Define a constant N for the size of the array
var num1 int // Declare global variables num1 and math
var math [N+1]int

func main() { // Main function is the entry point of the program
    var a, num2, ans, sum int = 0, 0, 0, 0 // Declare local variables a, num2, ans, sum, and math (shadowing the global variable)
    var i, j int = 0, 0 // Declare loop variables

    math[0] = 1 // Initialize the first element of math to 1
    
    fmt.Scanf("%d", &num1) // Read the number of elements in the first set of inputs
    for i = 0; i < num1; i++ { // Loop through num1 times
        fmt.Scanf("%d", &a) // Read each element
        sum += a // Update the sum
        for j = sum - a; j >= 0; j-- { // Loop to mark possible sums
           if math[j] == 1 { math[j + a] = 1 } // If the sum j is possible, mark sum j+a as possible
        }
    }

    fmt.Scanf("%d", &num2) // Read the number of elements in the second set of inputs
    for i = 0; i < num2; i++ { // Loop through num2 times
        fmt.Scanf("%d", &ans) // Read each element
        if math[ans] == 1 { fmt.Printf("yes\n") } else { fmt.Printf("no\n") } // Check if the sum is possible and print the result
    }

    return // Return 0 to indicate successful execution
}

