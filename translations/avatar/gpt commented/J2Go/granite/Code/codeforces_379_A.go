
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a scanner object to read input from the user
    scan := bufio.NewScanner(os.Stdin)
    
    // Reading two integers from the user
    scan.Scan()
    a, _ := strconv.Atoi(scan.Text()) // The initial amount
    scan.Scan()
    b, _ := strconv.Atoi(scan.Text()) // The divisor
    
    // Initializing the result with the value of 'a'
    res := a
    
    // Loop to perform the division and accumulate the result
    for a >= b {
        // Add the quotient of a divided by b to the result
        res += (a / b)
        
        // Update 'a' to be the sum of the quotient and the remainder
        a = (a / b) + (a % b)
    }
    
    // Output the final result
    fmt.Println(res)
}

