// User inputs the maximum level of the set
maxLevel := int(input())

// User inputs two lists, x and y, separated by a newline
x := strings.Split(input(), " ")
y := strings.Split(input(), " ")

// Remove the first element from both lists, as they are not part of the sets
x = x[1:]
y = y[1:]

// Convert both lists to sets for faster set operations
x = make(map[int]struct{})
for _, v := range x {
    x[v] = struct{}{}
}
y = make(map[int]struct{})
for _, v := range y {
    y[v] = struct{}{}
}

// Check if zero is present in the first set
if _, ok := x[0]; ok {
    // If it is, remove it
    delete(x, 0)
}
// Else, check if zero is present in the second set
else {
    if _, ok := y[0]; ok {
        // If it is, remove it
        delete(y, 0)
    }
}

// Combine both sets into a new set z
z := make(map[int]struct{})
for k := range x {
    z[k] = struct{}{}
}
for k := range y {
    z[k] = struct{}{}
}

// Check if the size of the combined set is equal to the maximum level
if len(z)!= maxLevel {
    // If not, print an error message
    fmt.Println("Oh, my keyboard!")
}
// Else, print a success message
else {
    fmt.Println("I become the guy.")
}

