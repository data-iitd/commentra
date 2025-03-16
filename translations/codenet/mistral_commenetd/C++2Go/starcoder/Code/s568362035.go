<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Global variables
var (
    n, m, Q int
    a       []int
    b       []int
    id      []int
    vis     []bool
    cnt     []int
)

// Main function
func main() {
    // Read input
    fmt.Scanf("%d%d", &n, &m)
    fmt.Scanf("%d", &Q)
    for i := 1; i <= Q; i++ {
        fmt.Scanf("%d", &a[i]) // Read queries
    }

    // Initialize variables
<<<<<<< HEAD
    k := 0
    j := Q
=======
    k, j := 0, Q
>>>>>>> 98c87cb78a (data updated)
    for j > 0 {
        // Find unvisited elements and add them to the output array
        if!vis[a[j]] {
            b[k+1] = a[j] // Add the element to the output array
            vis[a[j]] = true // Mark it as visited
            k++
        }
        j--
    }

    // Fill the output array with the remaining unvisited elements
<<<<<<< HEAD
    j = m
    i := m
=======
    j, i := m, m
>>>>>>> 98c87cb78a (data updated)
    for i > 0 {
        if!vis[i] {
            b[j] = i // Add the element to the output array
            j--
        }
        i--
    }

    // Assign indices to the output array elements
    for i := 1; i <= m; i++ {
        id[b[i]] = i // Assign index i to the element b[i]
    }

    // Process queries
    flag := true
    cnt[0] = n // Initialize counter array with the number of elements in the input array
    for i := Q; i > 0; i-- {
        t := id[a[i]] // Get the index of the element a[i] in the output array
        if cnt[t-1] > 0 { // If the previous element is still present in the input array
            cnt[t-1]-- // Decrease its counter
            cnt[t]++ // Increase the counter of the current element
            vis[t] = true // Mark it as visited
        } else if!vis[t] { // If the current element is not present in the input array
            flag = false // Set the flag to false and break the loop
            break
        }
    }

    // Check the result
    l := 0
    for l = 0; cnt[l] == 0; l++ { // Find the last element that was present in the input array
    }
    for i := l + 1; i < m; i++ {
        flag &= b[i] < b[i+1] // Check if the output array is sorted in ascending order after the last present element
    }

    // Print the result
    fmt.Println(flag)
}

