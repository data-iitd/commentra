
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to read a list of integers from input
func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &A[i])
	}
	return A
}

// Main function to execute the logic
func main() {
	A := readInts()  // Reading a list of integers
	n := len(A)  // Getting the length of the list
	sort.Ints(A)  // Sorting the list of integers in ascending order
	ans := 0  // Initializing the answer variable to accumulate the result
	
	// Looping through the last 2*n elements of the sorted list in reverse order
	for i := n - 2; i >= n-2*n-1; i -= 2 {
		ans += A[i]  // Adding the current element to the answer
	}
	
	fmt.Println(ans)  // Printing the final accumulated answer
}

// Entry point of the program
func main() {
	main()  // Calling the main function to execute the program
}

