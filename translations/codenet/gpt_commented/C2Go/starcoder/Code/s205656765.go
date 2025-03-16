package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for the number of coins of each type and the target value
    var A, B, C, X int

    // Input the number of coins of each type and the target value
    fmt.Scanf("%d", &A) // Number of 10 yen coins
    fmt.Scanf("%d", &B) // Number of 2 yen coins
    fmt.Scanf("%d", &C) // Number of 1 yen coins
    fmt.Scanf("%d", &X) // Target value in yen

    // Convert the target value from yen to the number of 50 yen coins
    X = X / 50

    // Iterate through all possible combinations of coins
    for i := 0; i <= A; i++ { // Loop through the number of 10 yen coins
        for j := 0; j <= B; j++ { // Loop through the number of 2 yen coins
            for k := 0; k <= C; k++ { // Loop through the number of 1 yen coins
                // Check if the current combination of coins equals the target value
                if X == (10 * i) + (2 * j) + k {
                    fmt.Println(i, j, k)
                }
            }
        }
    }

    // Output the total number of combinations that meet the target value
    fmt.Println(i, j, k)

    // 