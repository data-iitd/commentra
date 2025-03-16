package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to read an integer from input
func nextint() int {
    var c rune
    var s string
    fmt.Scanf("%c", &c)
    for c!= '-' && (c < '0' || c > '9') {
        fmt.Scanf("%c", &c)
    }
    if c == '-' {
        s = "-"
        fmt.Scanf("%c", &c)
    }
    for c >= '0' && c <= '9' {
        s += string(c)
        fmt.Scanf("%c", &c)
    }
    i, _ := strconv.Atoi(s)
    return i
}

func main() {
    n := nextint() // Read the number of nodes
    // Read the adjacency list from input
    var a [1000][999]int
    for i := 0; i < n; i++ {
        for j := 0; j < n - 1; j++ {
            a[i][j] = nextint() - 1
        }
    }
    // Build the edge representation
    var e1 [1000000]int
    var e2 [1000000]int
    for i := 0; i < n; i++ {
        for j := 0; j < n - 2; j++ {
            from := i + a[i][j] * n // Get unique index for the current edge
            to := i + a[i][j + 1] * n // Get unique index for the next edge
            // Store the edges in e1 and e2
            if e1[from] == 0 {
                e1[from] = to
            } else if e2[from] == 0 {
                e2[from] = to
            } else {
                fmt.Println("-1") // Output -1 if more than two edges are found
                return
            }
        }
    }
    var ans int
    // Compute the maximum distance for each node
    for i := 0; i < n; i++ {
        from := i + a[i][0] * n // Get unique index for the starting edge
        now := f(from, e1, e2) // Compute the distance
        if now < 0 {
            ans = -1 // Set answer to -1 if a cycle is detected
            break
        }
        if now > ans {
            ans = now
        }
    }
    fmt.Println(ans) // Output the final answer
}

// Recursive function to compute the maximum distance from a given node
func f(from int, e1 []int, e2 []int) int {
    if b[from] {
        return -1
    }
    if d[from] > 0 {
        return d[from]
    }
    b[from] = true
    var to int
    to = e1[from]
    var max int
    if to!= 0 {
        now := f(to, e1, e2)
        if now < 0 {
            return now
        }
        if now > max {
            max = now
        }
    }
    to = e2[from]
    if to!= 0 {
        now := f(to, e1, e2)
        if now < 0 {
            return now
        }
        if now > max {
            max = now
        }
    }
    b[from] = false
    return d[from] = max + 1
}

