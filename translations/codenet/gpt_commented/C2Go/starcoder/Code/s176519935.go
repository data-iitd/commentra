package main

import (
    "fmt"
    "math"
)

// Declare a max heap and a variable to track the size of the heap
var heap []int
var sz int

// Function to insert an element into the max heap
func push(x int) {
    i := sz
    sz++
    // Percolate up to maintain heap property
    for i > 0 {
        p := (i - 1) / 2
        if heap[p] >= x {
            break
        }
        heap[i] = heap[p]
        i = p
    }
    heap[i] = x
}

// Function to remove and return the maximum element from the max heap
func pop() int {
    ret := heap[0]
    x := heap[sz-1]
    sz--
    i := 0
    // Percolate down to maintain heap property
    for i*2+1 < sz {
        a := i*2 + 1
        b := i*2 + 2
        // Choose the larger child
        if b < sz && heap[b] > heap[a] {
            a = b
        }
        if heap[a] <= x {
            break
        }
        heap[i] = heap[a]
        i = a
    }
    heap[i] = x
    return ret
}

func main() {
    var n, m, i, j int
    var a []int
    // Read the number of elements and the number of operations
    fmt.Scanf("%d%d", &n, &m)
    // Read the elements into the array
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    // Insert all elements into the max heap
    for i = 0; i < n; i++ {
        push(a[i])
    }
    // Perform m operations of removing the max element and pushing back half of it
    for i = 0; i < m; i++ {
        tm := pop() // Get the maximum element
        tm /= 2 // Halve the maximum element
        push(tm) // Push the halved value back into the heap
    }
    var ans int
    // Calculate the sum of all elements remaining in the heap
    for i = 0; i < n; i++ {
        ans += heap[i]
    }
    // Print the final result
    fmt.Printf("%d\n", ans)
}

