package main

import "fmt"

// Define a constant for the modulus value
const mod = 998244353

// Declare a 2D array to store binomial coefficients
var nchoosek [4001][4001]int64

func main() {
    // Initialize the nchoosek array to store binomial coefficients up to 4000
    for i := 0; i < len(nchoosek); i++ {
        for j := 0; j < len(nchoosek[i]); j++ {
            nchoosek[i][j] = 1
        }
    }

    // Compute binomial coefficients using dynamic programming
    for i := 2; i < len(nchoosek); i++ {
        for j := 1; j < i; j++ {
            // C(i, j) = C(i-1, j) + C(i-1, j-1)
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod
        }
    }

    // Read the values of k and n from input
    var k, n int
    fmt.Scanf("%d %d", &k, &n)

    // Iterate through the range of 2 to 2*k
    for i := 2; i <= 2 * k; i++ {
        var pairs int
        // Calculate the number of pairs based on the current index i
        if i > k {
            pairs = k - i / 2 // More pairs than k
        } else {
            pairs = (i - 1) / 2 // Fewer pairs than k
        }

        // Calculate the number of active elements remaining
        var active int
        if i % 2 == 0 {
            active = k - 2 * pairs - 1 // Adjust active count for even i
        } else {
            active = k - 2 * pairs // Adjust active count for odd i
        }

        var times2 int64 = 1 // Initialize multiplier for choices
        var total int64 = 0 // Initialize total count

        // Calculate total combinations for the current number of pairs
        for j := 0; j <= pairs; j++ {
            // Calculate the number of ways to choose j pairs
            var choice int64 = times2 * nchoosek[pairs][j] % mod
            times2 = times2 * 2 % mod // Update multiplier for the next iteration

            // Skip if there are not enough active elements
            if active + j - 1 < 0 {
                continue
            }

            // Add combinations to the total based on active elements
            total += choice * nchoosek[n + active - 1][active + j - 1]

            // If i is even, add additional combinations
            if i % 2 == 0 {
                total += choice * nchoosek[n + active - 2][active + j - 1]
            }

            // Ensure total remains within modulus
            total %= mod
        }

        // Output the total combinations for the current i
        fmt.Println(total)
    }
}

