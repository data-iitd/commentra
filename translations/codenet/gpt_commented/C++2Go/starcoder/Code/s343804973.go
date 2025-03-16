package main

import (
    "fmt"
    "math/big"
    "os"
    "strconv"
    "strings"
)

// Declare global variables
var n, m, mod int
var C [310][310]int
var pre [310][310]int
var f [310][310]int

func main() {
    // Read input values for n, m, and mod
    fmt.Sscanf(os.Args[1], "%d %d %d", &n, &m, &mod)

    // Initialize the binomial coefficient array C
    C[0][0] = 1 // Base case: C(0, 0) = 1
    for i := 1; i <= n; i++ {
        C[i][0] = C[i][i] = 1 // C(i, 0) = C(i, i) = 1 for all i
        for j := 1; j < i; j++ {
            // Calculate C(i, j) using the recursive relation
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
        }
    }

    // Initialize the first row of f and pre arrays
    for i := 0; i <= m; i++ {
        f[1][i] = 1
        pre[1][i] = m - i + 1 // Base case for f and pre
    }

    // Fill the f and pre arrays for dynamic programming
    for i := 2; i <= n + 1; i++ {
        for j := 0; j <= m; j++ {
            // Calculate f[i][j] based on previous values
            for k := 1; k < i; k++ {
                f[i][j] += f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]
                f[i][j] %= mod
            }
        }
        // Update the pre array for the current row
        for j := m; j >= 0; j-- {
            pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod
        }
    }

    // Output the result which is f[n + 1][0]
    fmt.Println(f[n + 1][0])
}

