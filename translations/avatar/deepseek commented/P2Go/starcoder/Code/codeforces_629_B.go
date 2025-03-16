
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define the maximum number of time slots
const N = 368

// Initialize lists to store changes for males and females
var m [ N ] int
var f [ N ] int

func main() {
    // Read the number of operations
    n, _ := strconv.Atoi(readLine())

    // Read each line, strip newline, and split into gender, start time, and end time
    for i := 0; i < n; i++ {
        x, a, b := readLine()
        a, _ = strconv.Atoi(a)
        b, _ = strconv.Atoi(b)

        // Update the changes in the lists based on gender
        if x == "M" {
            m[a] += 2
            m[b] -= 2
        } else {
            f[a] += 2
            f[b] -= 2
    }

    // Initialize variables to store the maximum number of people and the current number of people
    a, b, c := 0, 0, 0

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for i := 0; i < N; i++ {
        a += m[i]
        b += f[i]
        if min(a, b) > c {
            c = min(a, b)
    }

    // Print the maximum number of people at any time slot
    fmt.Println(c)
}

// ReadLine reads a line from stdin and returns it as a string
func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    str, _, _ := buf.ReadLine()
    return strings.TrimRight(string(str), "\r\n")
}

// min returns the minimum of two integers
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

