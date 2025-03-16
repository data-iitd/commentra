// Initialize an empty dictionary to store the visited positions
record_of_movements := input()
x, y := 0, 0 // Initialize the starting position of the bug
d_movement := map[string]int{ // Define a dictionary to store the direction of movement
    "L": 0,
    "R": 0,
    "U": 0,
    "D": 0,
}
d := map[int]int{ // Initialize an empty dictionary to store the visited positions
    x: y,
}
bug := false // Initialize a boolean variable to check if the bug is trapped

// Iterate through each movement in the record
for _, move := range record_of_movements {
    // Save the current position of the bug
    temp := x, y

    // Move the bug based on the given direction
    x += d_movement[move][0]
    y += d_movement[move][1]

    // Check if the new position is already visited
    if _, ok := d[x];!ok {
        // If yes, check if there is a loop in the path
        for step, _ := range d_movement {
            if (x + d_movement[step][0], y + d_movement[step][1])!= temp && (x + d_movement[step][0], y + d_movement[step][1]) in d {
                // If a loop is found, set the bug is trapped flag
                bug = true
                break
            }
        }
    }

    // If the new position is not visited, set it as visited
    d[x] = y
}

// Check if the bug is trapped
if bug {
    fmt.Println("BUG")
} else {
    fmt.Println("OK")
}

