// Initialize an empty dictionary to store the visited positions
record_of_movements := input()
x, y := 0, 0 // Initialize the starting position of the bug
d_movement := map[string][2]int{ // Define a dictionary to store the direction of movement
    "L": [0, -1],
    "R": [0, 1],
    "U": [1, 0],
    "D": [-1, 0]
}
d := map[string]string{ // Initialize an empty dictionary to store the visited positions
    fmt.Sprintf("%d %d", x, y): ""
}
bug := false // Initialize a boolean variable to check if the bug is trapped

// Iterate through each movement in the record
for _, move := range record_of_movements {
    // Save the current position of the bug
    temp := fmt.Sprintf("%d %d", x, y)

    // Move the bug based on the given direction
    x += d_movement[move][0]
    y += d_movement[move][1]

    // Check if the new position is already visited
    if _, ok := d[fmt.Sprintf("%d %d", x, y)]; !ok {
        // If yes, check if there is a loop in the path
        for step := range d_movement {
            if fmt.Sprintf("%d %d", x+d_movement[step][0], y+d_movement[step][1]) != temp && fmt.Sprintf("%d %d", x+d_movement[step][0], y+d_movement[step][1]) in d {
                // If a loop is found, set the bug is trapped flag
                bug = true
                break
            }
        }
    }

    // If the new position is not visited, set it as visited
    d[fmt.Sprintf("%d %d", x, y)] = ""
}

// Check if the bug is trapped
if bug {
    fmt.Println("BUG")
} else {
    fmt.Println("OK")
}

