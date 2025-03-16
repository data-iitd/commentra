// Initialize an empty list to store the sequence
L := []int{}

// Read input (not used, but could be for prompting the user)
fmt.Scanln()

// Initialize a variable 'r' to keep track of the current number to be added to the list
r := 1

// Read a line of input, split it into parts, and iterate over each part
for _, k := range strings.Split(input(), " ") {
    // Extend the list 'L' by adding 'r' for 'int(k)' times
    for i := 0; i < int(k); i++ {
        L = append(L, r)
    }
    // Increment 'r' for the next number
    r++
}

// Read another line of input (not used, but could be for prompting the user)
fmt.Scanln()

// Read a line of input, split it into parts, and iterate over each part
for _, j := range strings.Split(input(), " ") {
    // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
    fmt.Println(L[int(j)-1])
}

