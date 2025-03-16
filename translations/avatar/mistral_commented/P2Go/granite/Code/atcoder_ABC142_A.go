
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read an integer input from the user
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine())
    // Initialize a variable t to zero
    t := 0
    // Iterate through the range of integers from 0 to n-1
    for i := 0; i < n; i++ {
        // Check if the index i is odd
        if i+1&1 == 1 {
            // If it is odd, increment the variable t by 1
            t++
        }
    }
    // Print the result t/n as the output
    fmt.Println(float64(t) / float64(n))
}

