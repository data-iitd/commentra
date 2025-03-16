package main

import (
    "fmt"
    "sort"
)

// Entry point of the program
func main() {
    // Read the number of work items
    var n int
    fmt.Scan(&n)

    // Initialize a slice to hold the work items
    var ws works = make([]work, n)

    // Read each work item's time and limit
    for i := 0; i < n; i++ {
        var a, n int
        fmt.Scan(&a, &n)
        ws[i] = work{a, n} // Store the work item in the slice
    }

    // Sort the work items based on their limits
    sort.Sort(ws)

    // Initialize a variable to keep track of the cumulative time
    sum := int64(0)

    // Check if the cumulative time exceeds the limit for any work item
    for _, w := range ws {
        sum += int64(w.time) // Add the current work item's time to the sum
        if sum > int64(w.limit) {
            fmt.Println("No") // If the sum exceeds the limit, print "No"
            return
        }
    }

    // If all work items are within their limits, print "Yes"
    fmt.Println("Yes")
}

// Define a struct to represent a work item with time and limit
type work struct {
    time, limit int
}

// Define a slice of work items
type works []work

// Implement the sort.Interface for works
func (w works) Len() int           { return len(w) } // Return the length of the slice
func (w works) Swap(i, j int)      { w[i], w[j] = w[j], w[i] } // Swap two work items
func (w works) Less(i, j int) bool { return w[i].limit < w[j].limit } // Compare work items based on their limits
