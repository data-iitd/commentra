
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Declaring variables to hold input values and a counter
    var pandu, vundu, urdu, c int64 = 0
    
    // Reading three integer values from user input
    scanner.Scan()
    pandu, _ = strconv.ParseInt(scanner.Text(), 10, 64) // The first input value
    scanner.Scan()
    vundu, _ = strconv.ParseInt(scanner.Text(), 10, 64) // The second input value
    scanner.Scan()
    urdu, _ = strconv.ParseInt(scanner.Text(), 10, 64)  // The third input value
    
    // Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for i := int64(1); i <= urdu; i++ {
        c += i * pandu // Incrementing 'c' by the product of 'i' and 'pandu'
    }
    
    // Checking if the calculated sum 'c' is less than 'vundu'
    if c < vundu {
        fmt.Println("0") // If true, print "0"
    } else {
        // If 'c' is greater than or equal to 'vundu', print the difference
        fmt.Println(c - vundu)
    }
}

