// User inputs the maximum level of the set
maxLevel := 0
fmt.Scan(&maxLevel)

// User inputs two lists, x and y, separated by a newline
x := make([]int, 0)
y := make([]int, 0)
fmt.Scan(&x, &y)

// Remove the first element from both lists, as they are not part of the sets
x = x[1:]
y = y[1:]

// Convert both lists to sets for faster set operations
xSet := make(map[int]bool)
ySet := make(map[int]bool)
for _, v := range x {
    xSet[v] = true
}
for _, v := range y {
    ySet[v] = true
}

// Check if zero is present in the first set
if xSet[0] {
    // If it is, remove it
    delete(xSet, 0)
} else {
    // Else, check if zero is present in the second set
    if ySet[0] {
        // If it is, remove it
        delete(ySet, 0)
    }
}

// Combine both sets into a new set z
z := make(map[int]bool)
for k, _ := range xSet {
    z[k] = true
}
for k, _ := range ySet {
    z[k] = true
}

// Check if the size of the combined set is equal to the maximum level
if len(z) != maxLevel {
    // If not, print an error message
    fmt.Println("Oh, my keyboard!")
} else {
    // Else, print a success message
    fmt.Println("I become the guy.")
}

