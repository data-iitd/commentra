

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables for number of students and classes
    var n, m int

    // Read input from the standard input stream
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d %d\n", &n, &m)

    // Initialize slices's' and 'c' for storing student numbers and classes respectively
    s := make([]int, m)
    c := make([]int, m)

    // Read student numbers and classes from the standard input stream
    for i := 0; i < m; i++ {
        fmt.Fscanf(reader, "%d %d\n", &s[i], &c[i])
        // Decrement student numbers by 1 as they are 1-indexed
        s[i]--
    }

    // Check all strings of length 'n' for a valid combination of student numbers and classes
    for i := 0; i < 1000; i++ {
        // Convert the current number to a string
        st := strconv.Itoa(i)

        // Check if the length of the string is equal to 'n'
        if len(st)!= n {
            continue
        }

        // Initialize a flag 'f' to check if the current combination is valid
        f := true

        // Check each combination of student number and class
        for j := 0; j < m; j++ {
            // Check if the current character in the string matches the expected class
            if string(st[s[j]]) == string(c[j]+'0') {
                // If yes, continue to the next check
            } else {
                // If no, set the flag 'f' to false and break the loop
                f = false
                break
            }
        }

        // If all checks passed, print the current number and exit the program
        if f {
            fmt.Println(i)
            return
        }

    }

    // If no valid combination was found, print -1
    fmt.Println(-1)
}

