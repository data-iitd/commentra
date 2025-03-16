
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Call function B to execute its logic
    B()
}

func B() {
    reader := bufio.NewReader(os.Stdin) // Create a reader for input
    x, _ := strconv.ParseInt(readNext(reader), 10, 64) // Read input value x from the user
    i := 0 // Initialize counter variable i to 0
    sum := int64(100) // Initialize sum to 100

    // Loop until sum is less than x
    for sum < x {
        // Increase sum by 1% of its current value
        sum += sum / 100
        i++ // Increment counter variable i
    }

    // Output the number of iterations needed to exceed or meet x
    fmt.Println(i)
}

func readNext(reader *bufio.Reader) string {
    // Read the next line from the input reader
    line, _, _ := reader.ReadLine()
    return string(line)
}

