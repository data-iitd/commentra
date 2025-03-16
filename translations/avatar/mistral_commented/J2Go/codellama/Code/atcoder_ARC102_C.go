
package main

import (
    "fmt"
    "math"
)

// Declare a package 'main' and import the 'fmt' and 'math' packages

func main() {
    // The main function where the program starts execution

    mod := 998244353

    // Declare an integer variable 'mod' with the value 998244353

    nchoosek := make([][]int, 4001)

    // Declare a 2-dimensional integer array 'nchoosek' for storing binomial coefficients

    for i := 0; i < len(nchoosek); i++ {
        // Iterate through each row of the 'nchoosek' array

        nchoosek[i] = make([]int, 4001)

        // Initialize each row of the 'nchoosek' array with 4001 elements
    }

    // Initialize the 'nchoosek' array with dimensions 4001 x 4001 and fill it with zeros

    for i := 0; i < len(nchoosek); i++ {
        // Iterate through each row of the 'nchoosek' array

        nchoosek[i][0] = nchoosek[i][i] = 1

        // Set the first element of each row and the last element of each row to 1
    }

    // Initialize the first two elements of each row to 1

    for i := 2; i < len(nchoosek); i++ {
        // Iterate through each row starting from the third row

        for j := 1; j < i; j++ {
            // Iterate through each column starting from the second column

            nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % mod

            // Calculate the binomial coefficient 'nCj' using the formula 'nCj = nCj-1 + nCj-2'
        }
    }

    // Calculate the binomial coefficients using the recursive formula

    var k, n int

    // Declare integer variables 'k' and 'n' to store the input values

    fmt.Scan(&k, &n)

    // Read the first integer 'k' and the second integer 'n' from the console

    for i := 2; i <= 2*k; i++ {
        // Iterate through all possible values of 'i' from 2 to 2*k

        pairs := k - i/2

        // Declare an integer variable 'pairs' to store the number of pairs of 'i'

        if i > k {
            // If 'i' is greater than 'k', calculate the number of pairs

            pairs = k - i/2
        } else {
            // Otherwise, calculate the number of pairs for the first half of 'i'

            pairs = (i - 1) / 2
        }

        // Calculate the number of pairs based on the value of 'i'

        active := k - 2*pairs

        // Declare an integer variable 'active' to store the number of active elements

        if i%2 == 0 {
            // If 'i' is even, decrease the number of active elements by 1

            active -= 1
        }

        // If 'i' is even, decrease the number of active elements by 1

        times2 := 1

        // Declare an integer variable 'times2' to store the intermediate result for calculating 'nCj'

        total := 0

        // Declare an integer variable 'total' to store the final result

        for j := 0; j <= pairs; j++ {
            // Iterate through each pair 'j' from 0 to 'pairs'

            choice := times2 * nchoosek[pairs][j] % mod

            // Calculate the binomial coefficient 'nCj' using the previously calculated binomial coefficients

            times2 = times2 * 2 % mod

            // Multiply the result by 2 to get 'nCj+1'

            if active+j-1 < 0 {
                // If the number of active elements is less than 0, skip to the next iteration

                continue
            }

            // If the number of active elements is less than 0, skip to the next iteration

            total += choice * nchoosek[n+active-1][active+j-1]

            // Multiply the result with the corresponding element of the 'nchoosek' array

            if i%2 == 0 {
                // If 'i' is even, add the result multiplied by the element at the position 'n+active-2, active+j-1'

                total += choice * nchoosek[n+active-2][active+j-1]
            }

            // Add the result multiplied by the corresponding element of the 'nchoosek' array (if 'i' is even)

            total %= mod

            // Take the modulo to ensure the result does not exceed the value of 'mod'
        }

        // Calculate the final result by summing up all the intermediate results

        fmt.Println(total)

        // Print the final result to the console
    }
}

