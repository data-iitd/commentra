
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a Scanner object for user input
    sc := bufio.NewScanner(os.Stdin)

    // Read a long integer N from user input
    sc.Scan()
    N, _ := strconv.ParseInt(sc.Text(), 10, 64)

    // Initialize a variable to hold the minimum value
    min := int64(0)

    // Loop to read five long integers and find the minimum
    for i := 0; i < 5; i++ {
        // For the first iteration, directly assign the value to min
        if i == 0 {
            sc.Scan()
            min, _ = strconv.ParseInt(sc.Text(), 10, 64)
        } else {
            // For subsequent iterations, update min if a smaller value is found
            sc.Scan()
            val, _ := strconv.ParseInt(sc.Text(), 10, 64)
            if val < min {
                min = val
            }
        }
    }

    // Calculate the result by dividing N by min, rounding up, and adding 4
    result := int64(0)
    if N%min == 0 {
        result = N / min
    } else {
        result = N/min + 1
    }
    result += 4

    // Print the result
    fmt.Println(result)
}

