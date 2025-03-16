<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to calculate the score for each inning
func calcScore() int {
    var out int = 0 // Initialize the number of outs to 0
    var str string // Create a string to store the input string
    var score int = 0 // Initialize the score to 0
    var base int = 0 // Initialize the number of bases to 0

    // Loop through the three events in each inning
    for out < 3 {
        fmt.Print("Enter the event for this at bat (HIT, HOMERUN or OUT): ") // Ask for the event
        fmt.Scanf("%s", &str) // Read the event from the standard input

        // Check if the event is OUT
        if str == "OUT" {
            out++ // Increment the number of outs
        }
        // Check if the event is HIT
        else if str == "HIT" {
            // If there are already three bases, increment the score
            if base == 3 {
                score++
            }
            // If not, increment the number of bases
            else {
                base++
            }
        }
        // Check if the event is HOMERUN
        else if str == "HOMERUN" {
            score += (base + 1) // Add the number of bases and 1 to the score
            base = 0 // Reset the number of bases to 0
        }
    }

    // Return the score for this inning
    return score
}

<<<<<<< HEAD
// Main function to read the number of innings and call calcScore() for each inning
=======
// Main function to read the number of innings and call calc_score() for each inning
>>>>>>> 98c87cb78a (data updated)
func main() {
    var n int // Initialize the number of innings to be read
    var inning int = 0 // Initialize the current inning number to 0

    // Read the number of innings from the standard input
    fmt.Print("Enter the number of innings: ")
    fmt.Scanf("%d", &n)

<<<<<<< HEAD
    // Loop through each inning and call calcScore() to calculate the score
    for inning < n {
        var score int = calcScore() // Call calcScore() to calculate the score for this inning
=======
    // Loop through each inning and call calc_score() to calculate the score
    for inning < n {
        var score int = calcScore() // Call calc_score() to calculate the score for this inning
>>>>>>> 98c87cb78a (data updated)
        fmt.Printf("%d\n", score) // Print the score for this inning
        inning++ // Increment the current inning number
    }
}

