// Read the first line of input which indicates the number of iterations
firstline, _ := strconv.Atoi(input())

// Initialize total to keep track of the accumulated value
total := 0

// Create an empty list to store the memory of actions taken
memory := make([]string, 0)

// Loop through the range defined by firstline
for x := 0; x < firstline; x++ {
    // Read two integers A and G from input, separated by space
    A, G, _ := strconv.Atoi(input())

    // Check if adding A to total does not exceed the limit of 500
    if total+A <= 500 {
        // If within limit, add A to total
        total += A
        // Record the action "A" in memory
        memory = append(memory, "A")
    } else {
        // If limit exceeded, subtract G from total
        total -= G
        // Record the action "G" in memory
        memory = append(memory, "G")
    }
}

// Print the sequence of actions taken as a single string
fmt.Println(strings.Join(memory, ""))

