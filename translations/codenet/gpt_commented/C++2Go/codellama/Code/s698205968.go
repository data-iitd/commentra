package main

import "fmt"

func main() {
    // Declare variables to hold marks for midterm, final, and retake
    var m, f, r int

    // Continuously read input until the termination condition is met
    for {
        // Read input
        fmt.Scan(&m, &f, &r)

        // Check if either midterm or final score is -1, indicating failure
        if m == -1 || f == -1 {
            fmt.Println("F") // Output "F" for failure
        }
        // Check if the total score is 80 or more for grade A
        else if m + f >= 80 {
            fmt.Println("A") // Output "A" for excellent performance
        }
        // Check if the total score is between 65 and 79 for grade B
        else if m + f >= 65 {
            fmt.Println("B") // Output "B" for good performance
        }
        // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
        else if m + f >= 50 || r >= 50 {
            fmt.Println("C") // Output "C" for satisfactory performance
        }
        // Check if the total score is between 30 and 49 for grade D
        else if m + f >= 30 {
            fmt.Println("D") // Output "D" for passing but needs improvement
        }
        // If none of the above conditions are met, output "F"
        else {
            fmt.Println("F") // Output "F" for failure
        }

        // Print a newline after each grade output
        fmt.Println()

        // Check if the termination condition is met
        if m == -1 && f == -1 && r == -1 {
            break // Break out of the loop
        }
    }
}

