package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold marks for midterm, final, and retake
    var m, f, r int

    // Continuously read input until the termination condition is met
    for {
        // Read input from stdin
        fmt.Scanf("%d %d %d", &m, &f, &r)

        // Check if either midterm or final score is -1, indicating failure
        if m == -1 || f == -1 {
            fmt.Println("F") // Output "F" for failure
        } else {
            // Check if the total score is 80 or more for grade A
            if m+f >= 80 {
                fmt.Println("A") // Output "A" for excellent performance
            } else {
                // Check if the total score is between 65 and 79 for grade B
                if m+f >= 65 {
                    fmt.Println("B") // Output "B" for good performance
                } else {
                    // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
                    if m+f >= 50 || r >= 50 {
                        fmt.Println("C") // Output "C" for satisfactory performance
                    } else {
                        // Check if the total score is between 30 and 49 for grade D
                        if m+f >= 30 {
                            fmt.Println("D") // Output "D" for passing but needs improvement
                        } else {
                            fmt.Println("F") // Output "F" for failure
                        }
                    }
                }
            }
        }

        // Check if the input is the termination condition
        if m == -1 && f == -1 && r == -1 {
            break
        }
    }
}

