

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var t [4][4]string // Declare a 4x4 grid represented by a 2D array of strings
    var black, white, correct int // Initialize black and white counters and correct flag to 0

    reader := bufio.NewReader(os.Stdin) // Create a new bufio.Reader to read input from user

    for i := 0; i < 4; i++ { // Loop through 4 iterations to get input strings from user
        input, _ := reader.ReadString('\n') // Read input string from user and discard the newline character
        input = strings.TrimSpace(input) // Remove leading and trailing whitespace from the input string
        t[i] = strings.Split(input, "") // Convert input string to a slice of strings and assign it to the current row of the grid
    }

    for i := 0; i < 3; i++ { // Loop through the first 3 rows of the 4x4 grid represented by the 2D array 't'
        for j := 0; j < 3; j++ { // Loop through the first 3 columns of the current row
            if t[i][j] == "#" { // If current cell contains '#', increment 'black' counter
                black++
            } else { // If current cell contains '.', increment 'white' counter
                white++
            }

            // Check the neighboring cells and increment 'black' or 'white' counter accordingly
            if t[i][j+1] == "#" {
                black++
            } else {
                white++
            }

            if t[i+1][j] == "#" {
                black++
            } else {
                white++
            }

            if t[i+1][j+1] == "#" {
                black++
            } else {
                white++
            }

            // Check the current cell and its neighbors for winning conditions
            if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
                correct = 1 // If a winning condition is met, set 'correct' to 1 and break out of the loop
                break
            }

            // Reset black and white counters for the next iteration of the inner loop
            black = 0
            white = 0
        }
    }

    if correct == 1 { // If 'correct' is set to 1, print 'YES'
        fmt.Println("YES")
    } else { // If 'correct' is not set to 1, print 'NO'
        fmt.Println("NO")
    }
}

