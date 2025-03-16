
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Continuously read input until the termination condition is met
    for scanner.Scan() {
        // Split the input line into individual fields
        fields := strings.Fields(scanner.Text())

        // Check if the input line contains three fields and the first field is not "-1"
        if len(fields) == 3 && fields[0]!= "-1" {
            // Convert the fields to integers
            m, _ := strconv.Atoi(fields[0])
            f, _ := strconv.Atoi(fields[1])
            r, _ := strconv.Atoi(fields[2])

            // Check if either midterm or final score is -1, indicating failure
            if m == -1 || f == -1 {
                // Output "F" for failure
                fmt.Println("F")
            } else {
                // Check if the total score is 80 or more for grade A
                if m+f >= 80 {
                    // Output "A" for excellent performance
                    fmt.Println("A")
                } else {
                    // Check if the total score is between 65 and 79 for grade B
                    if m+f >= 65 {
                        // Output "B" for good performance
                        fmt.Println("B")
                    } else {
                        // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
                        if m+f >= 50 || r >= 50 {
                            // Output "C" for satisfactory performance
                            fmt.Println("C")
                        } else {
                            // Check if the total score is between 30 and 49 for grade D
                            if m+f >= 30 {
                                // Output "D" for passing but needs improvement
                                fmt.Println("D")
                            } else {
                                // Output "F" for failure
                                fmt.Println("F")
                            }
                        }
                    }
                }
            }
        }

        // Print a newline after each grade output
        fmt.Println()
    }

    // Check for any errors during input reading
    if err := scanner.Err(); err!= nil {
        fmt.Println("Error:", err)
    }
}
