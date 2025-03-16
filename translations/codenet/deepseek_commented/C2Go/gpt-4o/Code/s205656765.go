package main  // Declare the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Main function where the execution of the program begins
    var A, B, C, X int  // Declare variables to store the number of each coin type and the target sum
    var kosu int  // Declare and initialize a counter for the number of combinations

    // Read the number of each coin type and the target sum from the user
    fmt.Scan(&A)
    fmt.Scan(&B)
    fmt.Scan(&C)
    fmt.Scan(&X)

    // Normalize the target sum X by dividing it by 50
    X = X / 50

    // Nested loops to iterate over all possible combinations of the coins
    for i := 0; i <= A; i++ {  // Loop over the number of 500 yen coins
        for j := 0; j <= B; j++ {  // Loop over the number of 100 yen coins
            for k := 0; k <= C; k++ {  // Loop over the number of 50 yen coins
                if X == (10*i) + (2*j) + k {  // Check if the sum of the coin values equals the normalized target sum
                    kosu++  // Increment the counter if the condition is met
                }
            }
        }
    }

    // Print the final count of combinations
    fmt.Println(kosu)
}

// <END-OF-CODE>
