// Take the first line as an input
firstline, _ := strconv.Atoi(input())

// Initialize total and memory lists
total := 0
memory := []string{}

// Loop through the given number of lines
for x := 0; x < firstline; x++ {
    // Take two integers as input, A and G
    A, G, _ := strconv.Atoi(input())
    
    // Check if adding A to the total memory usage is within the limit
    if total + A <= 500 {
        // If yes, add A to the total and append 'A' to the memory list
        total += A
        memory = append(memory, "A")
    } else {
        // If no, subtract G from the total and append 'G' to the memory list
        total -= G
        memory = append(memory, "G")
    }
}

// Print the final memory state
fmt.Println(strings.Join(memory, ""))

