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

// Function prototypes
func init(i int)
func move(i int)

// Global variables
var n, x, y int
var fld [21][21]int

func main() {
    var m int
    // Read the number of items to be collected
    fmt.Scanf("%d", &n)
    // Initialize the grid and the robot's position
    init(n)
    // Read the number of movements
    fmt.Scanf("%d", &m)
    // Perform the movements
    move(m)
    // Output the result
    fmt.Printf("%s\n", n > 0? "No" : "Yes")
}

// Initializes the grid with items and sets the robot's starting position
func init(i int) {
    var a, b int
    // Set the starting position of the robot
    x, y = 10, 10
    // Clear the grid
    for i := 0; i < 21; i++ {
        for j := 0; j < 21; j++ {
            fld[i][j] = 0
        }
    }
    // Read the positions of items and mark them in the grid
    for ; i > 0; i-- {
        fmt.Scanf("%d %d", &a, &b)
        fld[b][a] = 1
    }
}

// Moves the robot according to the given directions and collects items
func move(i int) {
    var a, d int
    var buf string
    // Read each movement and execute it
    for ; i > 0; i-- {
        fmt.Scanf("%1s %d", &buf, &a)
        // Determine the direction and convert it to an index
        switch buf[0] {
        case 'N':
            d = 0
        case 'E':
            d = 1
        case 'S':
            d = 2
        case 'W':
            d = 3
        }
        // Move the robot and collect items
        for ; a > 0; a-- {
            // Update the robot's position based on the direction
            d % 2 == 0? x-- : x++
            d == 0? y-- : d == 2? y++ : 0
            // Check if the robot collects an item
            if fld[y][x] > 0 {
                fld[y][x] = 0
                n--
            }
        }
    }
}

