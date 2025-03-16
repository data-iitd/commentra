

package main

import (
    "bufio"
    "fmt"
    "os"
)

const MOD = 998244353

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    // Read the input values for A, B, C, and D
    A, _ := fmt.Fscanf(in, "%d\n", new(int))
    B, _ := fmt.Fscanf(in, "%d\n", new(int))
    C, _ := fmt.Fscanf(in, "%d\n", new(int))
    D, _ := fmt.Fscanf(in, "%d\n", new(int))

    // Initialize the dp array for the starting point (A, B)
    dp := make([][]int64, C+1)
    for i := range dp {
        dp[i] = make([]int64, D+1)
        dp[i][B] = 1
    }

    // Iterate over the range from A to C and from B to D
    for c := A; c <= C; c++ {
        for d := B; d <= D; d++ {
            // Skip the starting point (A, B)
            if c == A && d == B {
                continue
            }

            // Calculate the answer based on previous states
            ans := int64(0)
            if c > A {
                part := dp[c-1][d]
                ans = (part * int64(d)) % MOD
            }
            if d > B {
                part := dp[c][d-1]
                ans = (ans + (part * int64(c)) % MOD) % MOD
            }
            if c > A && d > B {
                ans = (ans - (dp[c-1][d-1]*int64(c-1)*int64(d-1))%MOD + MOD) % MOD
            }

            // Store the result in dp array
            dp[c][d] = ans
        }
    }

    // Output the result for the final state (C, D)
    fmt.Fprintf(out, "%d\n", dp[C][D])
    out.Flush()
}

