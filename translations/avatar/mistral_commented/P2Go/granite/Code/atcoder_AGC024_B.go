
###
package main

import (
	"bufio"
	"fmt"
	"os"
)

// This is the main function that is called when we run the script.
// It takes an input of an integer N and a list P of N integers as arguments.
// It then calls the editorial function with these arguments.
func main() {
	// Initialize a scanner to read input from the standard input.
	scanner := bufio.NewScanner(os.Stdin)
	// Read the number of test cases N from the standard input.
	scanner.Scan()
	N := readInt(scanner.Text(), 0)
	// Initialize a slice P of size N to store the N integers.
	P := make([]int, N)
	// Read N integers from the standard input and store them in the slice P.
	for i := 0; i < N; i++ {
		scanner.Scan()
		P[i] = readInt(scanner.Text(), 0)
	}
	// Call the editorial function with N and P as arguments.
	editorial(N, P)
}

// This function calculates the answer based on the given input.
func editorial(N int, P []int) {
	// Base case: if there is only one element in the list, the answer is 0.
	if N == 1 {
		fmt.Println(0)
		return
	}
	// Initialize an array a of size N+1 with all elements initialized to 0.
	a := make([]int, N+1)
	// Iterate through the list P and assign each element its index in the array a.
	for i, p := range P {
		a[p] = i
	}
	// Initialize two variables: tmp to keep track of the current streak,
	// and max_len to keep track of the maximum streak.
	tmp := 1
	max_len := 1
	// Iterate through the array a from the second element to the last.
	for i := 1; i < N; i++ {
		// If the current element has a smaller index than the previous one,
		// increment the streak and update max_len if necessary.
		if a[i] < a[i+1] {
			tmp += 1
			max_len = max(max_len, tmp)
		} else {
			// Otherwise, reset the streak to 1.
			tmp = 1
		}
	}
	// Calculate the answer as the difference between the total number of elements
	// and the maximum streak.
	ans := N - max_len
	// Print the answer.
	fmt.Println(ans)
}

// This function is used for testing purposes and is not called in the main function.
func WA(N int, P []int) {
	// Initialize two variables: tmp to keep track of the current streak,
	// and ans to keep track of the maximum answer.
	tmp := 0
	ans := 0
	// Iterate through the list P and calculate the answer based on the current streak.
	for i, p := range P {
		// If the current element is the first one or its previous element plus one,
		// increment the streak and update ans if necessary.
		if i == 0 || P[i-1]+1 == p {
			tmp += 1
			ans = max(ans, tmp)
		} else {
			// Otherwise, reset the streak to 1.
			tmp = 1
		}
	}
	// Print the answer.
	fmt.Println(N - ans)
}

// This function reads an integer from a string at a given index.
func readInt(s string, from int) int {
	res := 0
	for ; from < len(s); from++ {
		if s[from] =='' {
			break
		}
		res = res*10 + int(s[from]-'0')
	}
	return res
}

// This function returns the maximum of two integers.
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

// This line is executed only if the script is run as the main module, not imported as a module.
func main() {
	// Call the main function.
	main()
}
