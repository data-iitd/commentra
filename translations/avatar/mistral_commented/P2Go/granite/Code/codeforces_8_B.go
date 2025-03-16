
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the record of movements:")
    record, _ := reader.ReadString('\n')
    record = strings.TrimSpace(record)

    x, y := 0, 0 // Initialize the starting position of the bug
    d_movement := map[string][2]int{ // Define a map to store the direction of movement
        "L": {0, -1},
        "R": {0, 1},
        "U": {1, 0},
        "D": {-1, 0},
    }
    d := map[[2]int]string{ // Initialize an empty map to store the visited positions
        {x, y}: "",
    }
    bug := false // Initialize a boolean variable to check if the bug is trapped

    // Iterate through each movement in the record
    for _, move := range record {
        // Save the current position of the bug
        temp := [2]int{x, y}

        // Move the bug based on the given direction
        x += d_movement[string(move)][0]
        y += d_movement[string(move)][1]

        // Check if the new position is already visited
        if _, ok := d[[2]int{x, y}];!ok {
            // If yes, check if there is a loop in the path
            for _, step := range d_movement {
                if [2]int{x + step[0], y + step[1]}!= temp && [2]int{x + step[0], y + step[1]} in d {
                    // If a loop is found, set the bug is trapped flag
                    bug = true
                    break
                }
            }
        }

        // If the new position is not visited, set it as visited
        d[[2]int{x, y}] = ""
    }

    // Check if the bug is trapped
    if bug {
        fmt.Println("BUG")
    } else {
        fmt.Println("OK")
    }
}
