package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare a variable to hold the number of submissions
    var n int
    // Read the number of submissions from the user
    fmt.Scanf("%d\n", &n)

    // Initialize counters for different result types
    ac_count := 0 // Count of Accepted submissions
    wa_count := 0 // Count of Wrong Answer submissions
    tle_count := 0 // Count of Time Limit Exceeded submissions
    re_count := 0 // Count of Runtime Error submissions

    // Loop through each submission
    for i := 0; i < n; i++ {
        var s string
        // Read the result of the current submission
        fmt.Scanf("%s\n", &s)

        // Increment the respective counter based on the result
        if s == "AC" {
            ac_count += 1 // Increment Accepted count
        } else if s == "WA" {
            wa_count += 1 // Increment Wrong Answer count
        } else if s == "TLE" {
            tle_count += 1 // Increment Time Limit Exceeded count
        } else if s == "RE" {
            re_count += 1 // Increment Runtime Error count
        }
    }

    // Output the counts of each result type
    fmt.Printf("AC x %d\n", ac_count) // Display Accepted count
    fmt.Printf("WA x %d\n", wa_count) // Display Wrong Answer count
    fmt.Printf("TLE x %d\n", tle_count) // Display Time Limit Exceeded count
    fmt.Printf("RE x %d\n", re_count) // Display Runtime Error count
}

