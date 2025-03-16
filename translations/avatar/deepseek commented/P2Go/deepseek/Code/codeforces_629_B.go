package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Define the maximum number of time slots
	const N = 368
	
	// Initialize slices to store changes for males and females
	m := make([]int, N)
	f := make([]int, N)
	
	// Read the number of operations
	var n int
	fmt.Fscan(reader, &n)
	
	// Read each line, strip newline, and split into gender, start time, and end time
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = line[:len(line)-1]
		var x string
		var a, b int
		fmt.Sscanf(line, "%s %d %d", &x, &a, &b)
		b++
		
		// Update the changes in the slices based on gender
		if x == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}
	
	// Initialize variables to store the maximum number of people and the current number of people
	var a, b, c int
	
	// Calculate the cumulative sum of changes and find the maximum number of people at any time slot
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if min(a, b) > c {
			c = min(a, b)
		}
	}
	
	// Print the maximum number of people at any time slot
	fmt.Println(c)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
