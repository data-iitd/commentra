
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize the minimum value to a large number
    minA := int(pow(10, 9)) + 1
    // Initialize the number of ways to achieve the maximum profit
    num := 0

    // Read the number of elements and an unused variable 't'
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    // Create a slice to store the elements
    A := make([]int, n)

    // Read the elements into the slice
    for i := 0; i < n; i++ {
        A[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Iterate through the slice to find the maximum profit
    for i := 0; i < n; i++ {
        // Update the minimum value found so far
        if minA > A[i] {
            minA = A[i]
        } else {
            // Check if the current profit is equal to the maximum profit found so far
            if f == A[i]-minA {
                num++
            }
            // Update the maximum profit and reset the count if a new maximum is found
            if f < A[i]-minA {
                num = 1
                f = A[i] - minA
            }
        }
    }

    // Output the number of ways to achieve the maximum profit
    fmt.Println(num)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func pow(x, n int) int {
    result := 1
    for n > 0 {
        if n%2 == 1 {
            result *= x
        }
        x *= x
        n /= 2
    }
    return result
}

