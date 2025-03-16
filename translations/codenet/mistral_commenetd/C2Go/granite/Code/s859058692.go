
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    sum := 0 // Initialize sum to 0
    n, _ := strconv.Atoi(read(reader)) // Read the number of integers to be input from the user
    min := 1000000001 // Initialize min to a large value
    max := -1000000001 // Initialize max to a small value
    
    // Iterate through each integer input
    for i := 0; i < n; i++ {
        m, _ := strconv.Atoi(read(reader)) // Read an integer input and assign it to m
        sum += m // Add the current integer input to the sum
        
        // Update min and max values if the current input is smaller or larger
        if min > m {
            min = m // Set min to the current input if it's smaller
        }
        if max < m {
            max = m // Set max to the current input if it's larger
        }
    }
    
    // Print the minimum value, maximum value, and sum of the input integers
    fmt.Printf("%d %d %d\n", min, max, sum) // Use %d to print integers
}

func read(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine()
    return string(str)
}

