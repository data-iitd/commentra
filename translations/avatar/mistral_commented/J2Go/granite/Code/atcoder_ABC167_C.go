

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initialize scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of rows and columns from the input
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    m, _ := strconv.Atoi(scanner.Text())

    // Read the 2D array 'a' from the input
    a := make([][]int, n)
    for i := 0; i < n; i++ {
        a[i] = make([]int, m+1)
        for j := 0; j <= m; j++ {
            scanner.Scan()
            a[i][j], _ = strconv.Atoi(scanner.Text())
        }
    }

    // Initialize variables for binary search tree traversal
    min := int(^uint(0) >> 1)
    x := 0 // Value to search for

    // Perform binary tree traversal
    for i := 0; i < 1<<n; i++ {
        status := make([]int, n) // Initialize status array for current binary tree node

        // Set the status of each node based on the current binary tree node
        for j := 0; j < n; j++ {
            if (1&i>>j) == 1 { // If the current binary tree node has a '1' at the j-th position
                status[j] = 1 // Set the status of the j-th node to '1'
            }
        }

        // Initialize result array for the current binary tree node
        res := make([]int, m+1)

        // Calculate the sum of elements in the current row for each column
        for j := 0; j < n; j++ {
            if status[j] == 1 { // If the j-th node is included in the current binary tree
                for k := 0; k <= m; k++ {
                    res[k] += a[j][k] // Add the element in the current column to the sum
                }
            }
        }

        // Check if the sum of elements in the current row for each column is greater than or equal to 'x'
        flag := true
        for j := 1; j <= m; j++ {
            if res[j] < x { // If the sum of elements in the current column is less than 'x'
                flag = false // Set the flag to 'false' and break the loop
                break
            }
        }

        // If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
        if flag {
            min = int(math.Min(float64(min), float64(res[0]))) // Update the minimum value with the sum of elements in the first column
        }
    }

    // Print the minimum value if it exists, otherwise print '-1'
    if min == int(^uint(0) >> 1) {
        fmt.Println(-1)
    } else {
        fmt.Println(min)
    }
}

