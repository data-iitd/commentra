// Read the input string representing movements
record_of_movements := input()

// Initialize the starting coordinates (x, y) at (0, 0)
x, y := 0, 0

// Define the movement directions: Left (L), Right (R), Up (U), Down (D)
d_movement := map[string]int{
    "L": 0,
    "R": 0,
    "U": 0,
    "D": 0,
}

// Create a dictionary to track visited coordinates, starting with the initial position
d := map[int]int{
    x: y,
}

// Initialize a flag to detect if a bug occurs
bug := false

// Iterate through each movement in the input string
for _, move := range record_of_movements {
    // Store the current position before the move
    temp := x, y

    // Update the coordinates based on the movement direction
    x += d_movement[move][0]
    y += d_movement[move][1]

    // Check if the new position has already been visited
    if _, ok := d[x];!ok {
        // If not visited, check for potential bugs by looking at all movement directions
        for step, _ := range d_movement {
            // Check if moving in any direction from the new position leads to a visited position
            if (x + d_movement[step][0], y + d_movement[step][1])!= temp && \
               (x + d_movement[step][0], y + d_movement[step][1]) in d {
                // If a bug is detected, set the flag and break the loop
                bug = true
                break
            }
        }
    } else {
        // If the new position was already visited, set the bug flag
        bug = true
    }

    // If a bug has been detected, exit the loop
    if bug {
        break
    }

    // Mark the new position as visited
    d[x] = y
}

// After processing all movements, check if a bug was detected
if bug {
    // Print 'BUG' if a bug was found
    fmt.Println("BUG")
} else {
    // Print 'OK' if no bugs were found
    fmt.Println("OK")
}

