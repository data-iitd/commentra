package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// run is the function that runs the game
func run() {
    // Read the number of elements and the target value from input
    n, k := readInput()

    // Array to store the elements
    a := make([]int, n)

    // Read the elements into the array
    for i := 0; i < n; i++ {
        a[i] = readInput()
    }

    // Allocate memory for the dynamic programming array
    dp := make([]int, k + 1)

    // Iterate over each possible value from 1 to k
    for i := 1; i <= k; i++ {
        win := 0

        // Check each element to see if it can lead to a winning position
        for j := 0; j < n && a[j] <= i; j++ {
            // If there exists a move that leads to a losing position for the opponent
            if dp[i - a[j]] == 0 {
                win = 1
            }
        }

        // Store the result in the dp array: 1 if the current player can win, 0 otherwise
        dp[i] = win
    }

    // Output the result: "First" if the first player can win, otherwise "Second"
    fmt.Printf("%s\n", dp[k] == 1? "First" : "Second")
}

// readInput is a helper function to read input from stdin
func readInput() int {
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    return strconv.Atoi(input)
}

// main is the entry point of the program
func main() {
    run()
}

