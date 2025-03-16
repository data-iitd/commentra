// Read an integer input which represents the number of lists to be processed
n, _ := strconv.Atoi(input())

// Initialize an empty list to store the input lists
q := make([][]string, 0)

// Initialize a counter to keep track of the matching conditions
count := 0

// Loop to read 'n' lines of input and store them in the list 'q'
for i := 0; i < n; i++ {
	// Read a line of input, split it into a list of strings, and append it to 'q'
	a := strings.Split(input(), " ")
	q = append(q, a)
}

// Nested loop to compare each list in 'q' with every other list
for j := 0; j < len(q); j++ {
	for k := 0; k < len(q); k++ {
		// Skip comparison if both lists are the same
		if k == j {
			continue
		}
		// Check if the first element of list 'j' matches the last element of list 'k'
		if q[j][0] == q[k][len(q[k])-1] {
			// Increment the count if the condition is met
			count++
		} else {
			// Continue to the next iteration if the condition is not met
			continue
		}
	}
}

// Print the final count of matching conditions
fmt.Println(count)

