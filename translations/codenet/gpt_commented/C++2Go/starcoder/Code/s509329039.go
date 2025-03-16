package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of constraints (n) and the number of conditions (m)
    n, m := 0, 0
    fmt.Scanf("%d %d\n", &n, &m)

    // Initialize vectors to store the positions (s) and corresponding values (c)
    s := make([]int, m)
    c := make([]int, m)

    // Read the constraints into the vectors
    for i := 0; i < m; i++ {
        fmt.Scanf("%d %d\n", &s[i], &c[i])
        s[i]-- // Adjust for 0-based indexing
    }

    // Iterate through all possible numbers from 0 to 999
    for i := 0; i < 1000; i++ {
        st := strconv.Itoa(i) // Convert the number to a string

        // Skip numbers that do not have the required length
        if len(st)!= n {
            continue
        }

        // Flag to check if the current number satisfies all conditions
        f := 1

        // Check each condition against the current number
        for j := 0; j < m; j++ {
            if st[s[j]] == byte(c[j]+'0') {
                // Condition is satisfied
            } else {
                // Condition is not satisfied, set flag to 0
                f = 0
            }
        }

        // If all conditions are satisfied, print the number and exit
        if f {
            fmt.Println(i)
            return
        }
    }

    // If no valid number is found, output -1
    fmt.Println(-1)
}

