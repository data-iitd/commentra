
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to calculate the absolute value of a number
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func main() {
    // Initialize variables
    var N, t, x, y, nx, ny, nt, tmp int
    var err error
    var line string
    var lines []string
    var reader *bufio.Reader = bufio.NewReader(os.Stdin)

    // Read the number of test cases
    line, err = reader.ReadString('\n')
    if err!= nil {
        panic(err)
    }
    N, err = strconv.Atoi(strings.TrimSpace(line))
    if err!= nil {
        panic(err)
    }

    // Loop through each test case
    for i := 0; i < N; i++ {
        // Read the time and coordinates for each test case
        line, err = reader.ReadString('\n')
        if err!= nil {
            panic(err)
        }
        lines = strings.Split(strings.TrimSpace(line), " ")
        t, err = strconv.Atoi(lines[0])
        if err!= nil {
            panic(err)
        }
        x, err = strconv.Atoi(lines[1])
        if err!= nil {
            panic(err)
        }
        y, err = strconv.Atoi(lines[2])
        if err!= nil {
            panic(err)
        }

        // Calculate the time left after accounting for the previous time and the distance traveled
        tmp = t - nt - (abs(x-nx) + abs(y-ny))

        // Check if the remaining time is negative or odd
        if tmp < 0 || tmp%2!= 0 {
            // If so, print "No" and exit the program
            fmt.Println("No")
            return
        }

        // Update the current position and time for the next iteration
        nt = t // Update the previous time
        nx = x // Update the previous x coordinate
        ny = y // Update the previous y coordinate
    }

    // If all test cases are valid, print "Yes"
    fmt.Println("Yes")
}

