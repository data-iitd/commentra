
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements from the user
    var n int
    fmt.Scanf("%d\n", &n)
    // Read the list of integers from the user input
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    // Initialize variables to track the current level and the number of turns
    current_level := 0
    counter := 0
    counter_turns := -1
    // Start a while loop that continues until all elements are processed
    for counter < len(a) {
        // Increment the turn counter
        counter_turns += 1
        // Iterate over the list 'a' to process each element
        for i := 0; i < len(a); i++ {
            // Check if the element is not -1 and is less than or equal to the current level
            if a[i]!= -1 && a[i] <= counter {
                // Increment the counter and mark the element as processed
                counter += 1
                a[i] = -1
        }
        // Reverse the list 'a' to process elements in a different order in the next iteration
        a = reverse(a)
    }
    // Print the number of turns taken to process all elements
    fmt.Printf("%d\n", counter_turns)
}

func reverse(a []int) []int {
    for i := 0; i < len(a)/2; i++ {
        a[i], a[len(a)-i-1] = a[len(a)-i-1], a[i]
    }
    return a
}

