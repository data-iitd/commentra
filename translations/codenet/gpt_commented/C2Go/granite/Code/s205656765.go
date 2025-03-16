
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables for the number of coins of each type and the target value
    var A, B, C, X int
    var i, j, k, kosu int = 0, 0, 0, 0 // Counter for the number of combinations that meet the target value

    // Input the number of coins of each type and the target value
    reader := bufio.NewReader(os.Stdin)
    A, _ = strconv.Atoi(readLine(reader)) // Number of 10 yen coins
    B, _ = strconv.Atoi(readLine(reader)) // Number of 2 yen coins
    C, _ = strconv.Atoi(readLine(reader)) // Number of 1 yen coins
    X, _ = strconv.Atoi(readLine(reader)) // Target value in yen

    // Convert the target value from yen to the number of 50 yen coins
    X = X / 50

    // Iterate through all possible combinations of coins
    for i = 0; i <= A; i++ { // Loop through the number of 10 yen coins
        for j = 0; j <= B; j++ { // Loop through the number of 2 yen coins
            for k = 0; k <= C; k++ { // Loop through the number of 1 yen coins
                // Check if the current combination of coins equals the target value
                if X == (10*i)+(2*j)+k {
                    kosu++ // Increment the counter if the combination matches
                }
            }
        }
    }

    // Output the total number of combinations that meet the target value
    fmt.Println(kosu)
}

func readLine(reader *bufio.Reader) string {
    line, _, err := reader.ReadLine()
    if err!= nil {
        panic(err)
    }

    return string(line)
}

