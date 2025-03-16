package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Declare a matrix to store values
var mat [3000][3000]int

// Declare a 3D dynamic programming array
var dp [3000][3000][4]int
// Declare a 1D array to store maximum values for each column
var dpl [3000]int

func main() {
    var rr, cc, k int

    // Read the number of rows (rr), columns (cc), and the number of values (k)
    fmt.Scanf("%d %d %d\n", &rr, &cc, &k)

    // Input the values into the matrix
    for i := 0; i < k; i++ {
        var r, c, v int
        fmt.Scanf("%d %d %d\n", &r, &c, &v)
        // Store the value in the matrix (adjusting for 0-based indexing)
        mat[r-1][c-1] = v
    }

    // Initialize the dynamic programming array with the value at the starting position
    dp[0][0][1] = mat[0][0]

    // Iterate through each cell in the matrix
    for y := 0; y < rr; y++ {
        for x := 0; x < cc; x++ {
            // Iterate through the four possible states (c)
            for c := 0; c < 4; c++ {
                v := mat[y][x] // Get the current cell value
                var q int // Variable to store the computed maximum value

                // Check if we are at the first column or if the current value is zero
                if c == 0 || v == 0 {
                    // If at the first column, take the value from dpl, else take the maximum from previous states
                    if x == 0 {
                        q = dpl[x]
                    } else {
                        q = int(max(float64(dpl[x]), float64(dp[y][x-1][c])))
                    }
                } else {
                    // If not at the first column, calculate the maximum considering the current value
                    if x == 0 {
                        q = dpl[x] + v
                    } else {
                        q = int(max(float64(dpl[x]+v), float64(max(float64(dp[y][x-1][c]), float64(dp[y][x-1][c-1]+v)))))
                    }
                }
                // Store the computed maximum value in the dp array
                dp[y][x][c] = q
            }
        }
        // Update the dpl array with the maximum values from the current row
        for x := 0; x < cc; x++ {
            dpl[x] = int(max(float64(max(float64(dp[y][x][0]), float64(dp[y][x][1]))), float64(max(float64(dp[y][x][2]), float64(dp[y][x][3])))))
        }
    }

    // Output the maximum value found in the last column
    fmt.Printf("%d\n", dpl[cc-1])
}

