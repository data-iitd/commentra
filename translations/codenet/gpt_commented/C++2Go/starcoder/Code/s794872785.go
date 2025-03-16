package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to solve the problem of finding the longest and most frequent string
func solve() bool {
    // Initialize variables to track the maximum size of strings and their counts
    maxsize := 0
    maxcnt := 0
    ans_num := 0
    ans_num2 := 0
    str_v := make([]string, 0)

    // Read strings from standard input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        str_v = append(str_v, scanner.Text())
    }

    // Loop through the vector to find the most frequent string
    for i := 0; i < len(str_v); i++ {
        cnt := 0
        // Count how many times the current string appears in the vector
        for j := 0; j < len(str_v); j++ {
            if str_v[i] == str_v[j] {
                cnt++
            }
        }
        // Check if the current count is greater than the previously recorded maximum count
        if maxcnt < cnt {
            maxcnt = cnt
            ans_num2 = i
        }
    }

    // Output the most frequent string and the longest string
    fmt.Printf("%s %s\n", str_v[ans_num2], str_v[ans_num])

    return true
}

func main() {
    // Set output format to fixed-point notation with 10 decimal places
    fmt.Printf("%.10f\n", 1.23456789)
    solve() // Call the solve function to process input and output results
}

