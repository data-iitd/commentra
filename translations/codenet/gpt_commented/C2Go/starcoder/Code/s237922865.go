package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare an integer variable to hold the number of inputs
    var n int
    // Read the number of integers to be processed
    fmt.Scanf("%d", &n)

    // Initialize counters for multiples of 4 and multiples of 2
    cnt4 := 0
    cnt2 := 0

    // Loop through each integer input
    for i := 0; i < n; i++ {
        var wk int
        // Read the current integer
        fmt.Scanf("%d", &wk)

        // Check if the integer is a multiple of 4
        if wk%4 == 0 {
            cnt4++
        }
        // Check if the integer is a multiple of 2 (but not a multiple of 4)
        else if wk%2 == 0 {
            cnt2++
        }
    }

    // Check if the total count of multiples of 4 and half the count of multiples of 2 is at least n/2
    if cnt4+cnt2/2 >= n/2 {
        // If the condition is met, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is not met, print "No"
        fmt.Println("No")
    }
}

