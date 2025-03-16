package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define a long long type for large integers
type ll int64

// Function to read input from stdin
func readInput(reader *bufio.Reader) (a []int) {
    // Read the number of elements
    n, _ := strconv.Atoi(readLine(reader))

    // Input the first array 'a'
    a = make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(readLine(reader))
    }

    // Input the second array 'b' and calculate the sum of positive differences
    b := make([]int, n)
    for i := 0; i < n; i++ {
        b[i], _ = strconv.Atoi(readLine(reader))

        // Check if the difference between corresponding elements of 'a' and 'b' is positive
        if a[i]-b[i] > 0 {
            // If positive, add the difference to'sum'
            sum += a[i] - b[i]
        }
    }

    // Output the final sum of positive differences
    fmt.Println(sum)
}

// Function to read a line of input from stdin
func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    readInput(reader)
}

