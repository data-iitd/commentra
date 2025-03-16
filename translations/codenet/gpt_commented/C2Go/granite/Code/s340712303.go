
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Define the main function
func main() {
    // Declare variables for input and calculations
    num1, num2, ans, sum int
    math := make([]int, 2001)

    // Initialize the first element of the math array to 1
    math[0] = 1

    // Read the number of elements for the first set
    num1, _ = strconv.Atoi(read())

    // Loop to read each element and update the possible sums
    for i := 0; i < num1; i++ {
        a, _ := strconv.Atoi(read()) // Read the current element
        sum += a // Update the total sum

        // Update the math array to reflect the new possible sums
        for j := sum - a; j >= 0; j-- {
            if math[j] == 1 {
                math[j+a] = 1 // Mark the new sum as possible
            }
        }
    }

    // Read the number of queries for possible sums
    num2, _ = strconv.Atoi(read())

    // Loop to check if each queried sum is possible
    for i := 0; i < num2; i++ {
        ans, _ = strconv.Atoi(read()) // Read the queried sum
        // Check if the queried sum is possible and print the result
        if math[ans] == 1 {
            fmt.Println("yes")
        } else {
            fmt.Println("no")
        }
    }
}

// Define a function to read input from the user
func read() string {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    return scanner.Text()
}

// End of the code