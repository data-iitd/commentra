
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read the number of test cases
	N := readInt()

	// Read the list of integers and sort it in descending order
	S := readIntSlice()
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	// Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	// Initialize an empty list to store the current subsequence
	cur := make([]int, 0, len(S))

	// Start from the first integer and include it in the subsequence
	cur = append(cur, S[0])
	flag[0] = false

	// For each integer in the sorted list
	for i := 0; i < N; i++ {
		// Initialize variables
		j := 0
		jM := len(cur)

		// Try to include the current integer in the subsequence
		for k := 0; k < len(S); k++ {
			// If the flag of the current integer is True and it is smaller than the last integer in the subsequence
			if flag[k] && S[k] < cur[j] {
				// Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
				cur = append(cur, S[k])
				j++
				flag[k] = false
				// If the length of the subsequence hasn't changed, break the loop
				if j == jM {
					break
				}
			}
		}

		// If we couldn't include any integer in the subsequence after the current one, return "No"
		if j == jM {
			fmt.Println("No")
			return
		}

		// Sort the subsequence in descending order
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}

	// If we could include all the integers in the subsequence, return "Yes"
	fmt.Println("Yes")
}

// Function to read an integer from standard input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		num, _ := fmt.Sscanf(scanner.Text(), "%d")
		return num
	}
	panic("Failed to read int.")
}

// Function to read a list of integers from standard input
func readIntSlice() []int {
	scanner := bufio.NewScanner(os.Stdin)
	var line string
	if scanner.Scan() {
		line = scanner.Text()
	} else {
		panic("Failed to read int slice.")
	}

	// Split the line into integers
	parts := make([]int, 0)
	for _, num := range strings.Split(line, " ") {
		part, _ := fmt.Sscanf(num, "%d")
		parts = append(parts, part)
	}
	return parts
}

// Translate the above Go code to Rust and end with comment "