
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an array to hold up to 1000 integers and variables for size and counters
    a := make([]int, 1000)
    n, _ := strconv.Atoi(readInput())
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(readInput())
    }

    // Perform a bubble sort on the array
    d := 0
    for i := 0; i < n; i++ {
        for j := n - 1; j >= i + 1; j-- {
            // If the current element is less than the previous one, swap them
            if a[j] < a[j - 1] {
                a[j], a[j - 1] = a[j - 1], a[j]
                d++ // Increment the swap counter
            }
        }
    }

    // Print the sorted array
    fmt.Print(a[0]) // Print the first element
    for i := 1; i < n; i++ {
        fmt.Printf(" %d", a[i]) // Print the remaining elements
    }

    // Print the total number of swaps made during sorting
    fmt.Printf("\n%d\n", d)
}

func readInput() string {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    return scanner.Text()
}

