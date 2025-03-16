package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Macro to calculate the absolute value of a number
const ABS = func(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func main() {
    // Declare variables
    var N, t, x, y, nx, ny, nt int

    // Read the number of test cases
    N, _ = strconv.Atoi(readLine())

    // Loop through each test case
    for i := 0; i < N; i++ {
        // Read the time and coordinates for each test case
        t, x, y = readThreeNums()

        // Calculate the time left after accounting for the previous time and the distance traveled
        tmp := t - nt - (ABS(x-nx) + ABS(y-ny))

        // Check if the remaining time is negative or odd
        if tmp < 0 || tmp%2!= 0 {
            // If so, print "No" and exit the program
            fmt.Println("No")
            os.Exit(0)
        }

        // Update the current position and time for the next iteration
        nt = t // Update the previous time
        nx = x // Update the previous x coordinate
        ny = y // Update the previous y coordinate
    }

    // If all test cases are valid, print "Yes"
    fmt.Println("Yes")
}

func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    str, _, _ := buf.ReadLine()
    return strings.TrimRight(string(str), "\r\n")
}

func readThreeNums() (int, int, int) {
    tmp := strings.Split(readLine(), " ")
    return parseInt(tmp[0]), parseInt(tmp[1]), parseInt(tmp[2])
}

func parseInt(str string) int {
    ret, _ := strconv.Atoi(str)
    return ret
}

