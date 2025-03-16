
package main

import (
    "bufio"
    "fmt"
    "os"
)

// Import the necessary packages for input/output operations

var (
    mod = 998244353 // Define a constant variable'mod' with the value 998244353
    nchoosek [4001][4001]int // Declare a 2-dimensional integer array 'nchoosek' with dimensions 4001 x 4001
)

func main() {
    // The main function where the program starts execution

    for i := 0; i < len(nchoosek); i++ {
        // Iterate through each row of the 'nchoosek' array

        nchoosek[i][0] = nchoosek[i][i] = 1 // Set the first element of each row and the last element of each row to 1
    }

    // Initialize the first two elements of each row to 1

    for i := 2; i < len(nchoosek); i++ {
        // Iterate through each row starting from the third row

        for j := 1; j < i; j++ {
            // Iterate through each column starting from the second column

            nchoosek[i][j] = (nchoosek[i-1][j] + nchoosek[i-1][j-1]) % mod // Calculate the binomial coefficient 'nCj' using the formula 'nCj = nCj-1 + nCj-2'
        }
    }

    // Calculate the binomial coefficients using the recursive formula

    reader := bufio.NewReader(os.Stdin) // Create a reader object to read input from the console

    k, _ := fmt.Fscanf(reader, "%d\n", &k) // Read the first integer 'k' from the console

    n, _ := fmt.Fscanf(reader, "%d\n", &n) // Read the second integer 'n' from the console

    for i := 2; i <= 2*k; i++ {
        // Iterate through all possible values of 'i' from 2 to 2*k

        pairs := k - i/2 // Calculate the number of pairs based on the value of 'i'

        active := k - 2*pairs // Calculate the number of active elements

        if i%2 == 0 {
            active-- // If 'i' is even, decrease the number of active elements by 1
        }

        times2 := 1 // Declare a variable 'times2' to store the intermediate result for calculating 'nCj'

        total := 0 // Declare a variable 'total' to store the final result

        for j := 0; j <= pairs; j++ {
            // Iterate through each pair 'j' from 0 to 'pairs'

            choice := int64(times2) * int64(nchoosek[pairs][j]) % mod // Calculate the binomial coefficient 'nCj' using the previously calculated binomial coefficients

            times2 = times2 * 2 % mod // Multiply the result by 2 to get 'nCj+1'

            if active+j-1 < 0 {
                continue // If the number of active elements is less than 0, skip to the next iteration
            }

            total += int(choice * int64(nchoosek[n+active-1][active+j-1])) // Multiply the result with the corresponding element of the 'nchoosek' array

            if i%2 == 0 {
                total += int(choice * int64(nchoosek[n+active-2][active+j-1])) // Add the result multiplied by the corresponding element of the 'nchoosek' array (if 'i' is even)
            }

            total %= mod // Take the modulo to ensure the result does not exceed the value of'mod'
        }

        fmt.Println(total) // Print the final result to the console
    }
}

// Translate the above Go code to C++ and end with comment "