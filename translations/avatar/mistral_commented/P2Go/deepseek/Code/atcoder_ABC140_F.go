package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read an integer from standard input
func I() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

// Function to read a list of integers from standard input
func LI() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(line), " ")
	ints := []int{}
	for _, num := range nums {
		intVal, _ := strconv.Atoi(num)
		ints = append(ints, intVal)
	}
	return ints
}

// Main function to solve the problem
func main() {
	// Read the number of test cases
	N := I()

	// Read the list of integers and sort it in descending order
	S := LI()
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})

	// Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
	flag := make([]bool, len(S))

	// Initialize an empty list to store the current subsequence
	cur := []int{}

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
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}

	// If we could include all the integers in the subsequence, return "Yes"
	fmt.Println("Yes")
}
