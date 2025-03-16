<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define the matrix and DP arrays
var mat [3000][3000]int
var dp [3000][3000][4]int64
var dpl [3000]int64

func main() {
    var rr, cc, k int
    var r, c, v int

    // Read input values for rows, columns, and number of non-zero elements
    fmt.Scanf("%d %d %d\n", &rr, &cc, &k)

    // Read each non-zero element's row, column, and value, and store in the matrix
    for i := 0; i < k; i++ {
        fmt.Scanf("%d %d %d\n", &r, &c, &v)
        mat[r-1][c-1] = v
    }

    // Initialize the DP table for the starting cell
    dp[0][0][1] = mat[0][0]

    // Fill the DP table
    for y := 0; y < rr; y++ {
        for x := 0; x < cc; x++ {
            for c := 0; c < 4; c++ {
                v := mat[y][x]
                var q int64
                // Update the DP table based on the current cell's value and previous values
                if c == 0 || v == 0 {
                    if x == 0 {
                        q = dpl[x]
                    } else {
                        q = int64(max(dpl[x], dp[y][x-1][c]))
                    }
                } else {
                    if x == 0 {
                        q = dpl[x] + int64(v)
                    } else {
                        q = int64(max(dpl[x]+v, max(dp[y][x-1][c], dp[y][x-1][c-1]+v)))
                    }
                }
                dp[y][x][c] = q
            }
        }
        // Update the maximum values for each column after processing the current row
        for x := 0; x < cc; x++ {
            dpl[x] = int64(max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3])))
        }
    }

    // Output the maximum value in the last column of the last row
<<<<<<< HEAD
    fmt.Printf("%d\n", dpl[cc-1])
=======
    fmt.Println(dpl[cc-1])
>>>>>>> 98c87cb78a (data updated)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

