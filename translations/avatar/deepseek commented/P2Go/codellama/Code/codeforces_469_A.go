// The code starts by taking input for the maximum level and two lists of integers.
max_level := 0
x := make([]int, 0)
y := make([]int, 0)

// Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
x = x[1:]
y = y[1:]
x = make([]int, len(x))
y = make([]int, len(y))
copy(x, x)
copy(y, y)

// If there's a 0 in either set, discard it from the set.
if 0 in x {
    x = x[:len(x)-1]
} else if 0 in y {
    y = y[:len(y)-1]
}

// Find the union of the two sets and check if its length is equal to the maximum level.
z := make([]int, len(x)+len(y))
copy(z, x)
copy(z, y)
if len(z) != max_level {
    fmt.Println("Oh, my keyboard!")
} else {
    fmt.Println("I become the guy.")
}

