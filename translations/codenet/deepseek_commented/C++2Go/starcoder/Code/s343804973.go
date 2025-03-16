<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Step 1: Define a type for long long integers
type int int64

var n, m, mod int
// Step 2: Declare variables for input values, binomial coefficients, and dynamic programming table

var C [310][310]int
// Step 3: Declare variables for binomial coefficients

var pre [310][310]int
// Step 4: Declare variables for dynamic programming table

var f [310][310]int
// Step 5: Declare variables for dynamic programming table

func main() {  // Step 6: Define the main function
    fmt.Scanf("%d%d%d", &n, &m, &mod)
    // Step 7: Read input values

    C[0][0] = 1
    // Step 8: Initialize the binomial coefficient table
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    for i := 1; i <= n; i++ {
        C[i][0] = C[i][i] = 1
        for j := 1; j < i; j++ {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
        }
    }

    // Step 9: Initialize the dynamic programming table
    for i := 0; i <= m; i++ {
        f[1][i] = 1
        pre[1][i] = m - i + 1
    }

    // Step 10: Compute the dynamic programming table
    for i := 2; i <= n+1; i++ {
        for j := 0; j <= m; j++ {
            for k := 1; k < i; k++ {
                f[i][j] += f[i-k][j]*pre[k][j+1] % mod * C[i-2][k-1] % mod
            }
        }
        for j := m; j >= 0; j-- {
            pre[i][j] = (pre[i][j+1] + f[i][j]) % mod
        }
    }

    // Step 11: Output the result
<<<<<<< HEAD
    fmt.Println(f[n+1][0])
=======
    fmt.Printf("%d\n", f[n+1][0])
>>>>>>> 98c87cb78a (data updated)
}

