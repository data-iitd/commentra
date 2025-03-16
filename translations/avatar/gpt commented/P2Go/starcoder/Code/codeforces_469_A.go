// Read the maximum level from user input
maxLevel := int(input())

// Read the levels completed by player X and convert them to a list of integers
x := strings.Split(input(), " ")

// Read the levels completed by player Y and convert them to a list of integers
y := strings.Split(input(), " ")

// Remove the first element from both lists, which represents the count of levels
x = x[1:]
y = y[1:]

// Convert the lists of levels into sets to eliminate duplicates
x = make(map[int]struct{})
for _, v := range x {
    x[v] = struct{}{}
}
y = make(map[int]struct{})
for _, v := range y {
    y[v] = struct{}{}
}

// Check if player X has completed level 0, if so, remove it from the set
if _, ok := x[0]; ok {
    delete(x, 0)
}
// If player X has not completed level 0, check if player Y has, and remove it if present
if _, ok := y[0]; ok {
    delete(y, 0)
}

// Create a union of both sets to combine all unique levels completed by both players
z := make(map[int]struct{})
for k := range x {
    z[k] = struct{}{}
}
for k := range y {
    z[k] = struct{}{}
}

// Check if the number of unique levels completed matches the maximum level
if len(z)!= maxLevel {
    // If not, print a message indicating that not all levels were completed
    fmt.Println("Oh, my keyboard!")
} else {
    // If all levels were completed, print a success message
    fmt.Println("I become the guy.")
}

