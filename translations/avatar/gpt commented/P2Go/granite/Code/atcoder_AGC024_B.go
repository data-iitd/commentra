
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of elements from user input
	N := readInt()

	// Read N integers from user input and store them in a slice P
	P := make([]int, N)
	for i := 0; i < N; i++ {
		P[i] = readInt()
	}

	// Call the editorial function to process the input
	editorial(N, P)
}

func editorial(N int, P []int) {
	// If there is only one element, the answer is 0 (no removals needed)
	if N == 1 {
		fmt.Println(0)
		return
	}

	// Create an array to store the positions of elements in P
	a := make([]int, N+1)

	// Fill the array 'a' with the indices of the elements in P
	for i, p := range P {
		a[p] = i
	}

	// Initialize temporary length and maximum length variables
	tmp := 1
	maxLen := 1

	// Iterate through the array to find the longest increasing subsequence
	for i := 1; i < N; i++ {
		if a[i] < a[i+1] {
			tmp++ // Increase the temporary length if the sequence is increasing
			maxLen = max(maxLen, tmp) // Update the maximum length found
		} else {
			tmp = 1 // Reset temporary length if the sequence is not increasing
		}
	}

	// Calculate the answer as the total elements minus the length of the longest subsequence
	ans := N - maxLen
	fmt.Println(ans)
}

func WA(N int, P []int) {
	// Initialize temporary length and answer variables
	tmp := 0
	ans := 0

	// Iterate through the list P to find the longest consecutive subsequence
	for i, p := range P {
		// Check if the current element is consecutive to the previous one
		if i == 0 || P[i-1]+1 == p {
			tmp++ // Increase temporary length for consecutive elements
		} else {
			ans = max(ans, tmp) // Update the answer with the maximum found
			tmp = 1 // Reset temporary length for a new sequence
		}
	}

	// Print the result as the total elements minus the longest consecutive subsequence
	fmt.Println(N - ans)
}

// Read an integer from user input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Entry point of the program
func main() {
	main()
}

