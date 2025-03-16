
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to calculate the score based on user input
func calc_score() int {
    out := 0 // Initialize the number of outs
    str := "" // Initialize the buffer to store user input
    score := 0 // Initialize the score
    base := 0 // Initialize the number of players on base

    // Loop until there are 3 outs
    for out < 3 {
        fmt.Fscanf(bufio.NewReader(os.Stdin), "%s", &str) // Read user input into str

        // Check if the input is "OUT"
        if str == "OUT" {
            out++ // Increment the out count
        } else if str == "HIT" { // Check if the input is "HIT"
            // If all bases are occupied, score a point
            if base == 3 {
                score++ // Increment the score
            } else {
                base++ // Move a player to the next base
            }
        } else if str == "HOMERUN" { // Check if the input is "HOMERUN"
            score += (base + 1) // Score based on players on base plus the hitter
            base = 0 // Reset bases after a homerun
        }
    }

    // Return the calculated score
    return score
}

// Main function to execute the program
func main() {
    n := 0 // Variable to hold the number of innings
    inning := 0 // Initialize the inning count

    // Read the number of innings from user input
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)

    // Loop through the number of innings
    for inning < n {
        fmt.Println(calc_score()) // Calculate and print the score for each inning
        inning++ // Increment the inning count
    }
}

// 