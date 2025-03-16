
package main
import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the value of n from input
    n, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    // Initialize a counter to keep track of odd numbers
    t := 0

    // Loop through each number from 0 to n-1
    for i := 0; i < n; i++ {
        // Check if the current index plus one is odd
        if i+1&1 == 1 {
            // Increment the counter if the condition is true
            t++
        }
    }

    // Calculate the ratio of odd numbers to the total numbers and print it
    fmt.Printf("%.6f\n", float64(t)/float64(n))
}

