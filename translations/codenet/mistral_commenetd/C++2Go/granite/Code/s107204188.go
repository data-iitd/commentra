

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize minimum value of array A to a large number
    minA := math.Pow(10, 9) + 1
    num := 0

    // Create a scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read number of elements and time t from the standard input
    scanner.Scan()
    line := scanner.Text()
    tokens := strings.Split(line, " ")
    n, _ := strconv.Atoi(tokens[0])
    t, _ := strconv.Atoi(tokens[1])

    // Create a slice A of size n to store the input elements
    A := make([]int, n)

    // Read each element of slice A from the standard input
    for i := 0; i < n; i++ {
        scanner.Scan()
        A[i], _ = strconv.Atoi(scanner.Text())

        // Check if the current element is smaller than the minimum value
        if minA > A[i] {
            // Update the minimum value of array A
            minA = A[i]
        } else {
            // Calculate the difference between the current element and the minimum value
            diff := A[i] - minA

            // If the difference is equal to the previous difference, increment the count of similar differences
            if f == diff {
                num++
            }
            // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            else if f < diff {
                num = 1
                f = diff
            }
        }
    }

    // Print the count of similar differences on the standard output
    fmt.Println(num)
}

