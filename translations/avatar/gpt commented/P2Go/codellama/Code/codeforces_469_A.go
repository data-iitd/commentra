// Read the maximum level from user input
maxLevel := readInt()

// Read the levels completed by player X and convert them to a list of integers
x := readIntList()

// Read the levels completed by player Y and convert them to a list of integers
y := readIntList()

// Remove the first element from both lists, which represents the count of levels
x = x[1:]
y = y[1:]

// Convert the lists of levels into sets to eliminate duplicates
x = set(x)
y = set(y)

// Check if player X has completed level 0, if so, remove it from the set
if 0 in x {
    x.Discard(0)
}
// If player X has not completed level 0, check if player Y has, and remove it if present
else if 0 in y {
    y.Discard(0)
}

// Create a union of both sets to combine all unique levels completed by both players
z := x.Union(y)

// Check if the number of unique levels completed matches the maximum level
if len(z) != maxLevel {
    // If not, print a message indicating that not all levels were completed
    fmt.Println("Oh, my keyboard!")
} else {
    // If all levels were completed, print a success message
    fmt.Println("I become the guy.")
}

