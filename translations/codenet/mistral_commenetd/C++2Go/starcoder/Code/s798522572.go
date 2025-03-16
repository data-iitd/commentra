<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Main function starts here
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array A and an input value T")
	// Read the first line of input from stdin
	input, _ := reader.ReadString('\n')
<<<<<<< HEAD
	// Split the input string into a slice of strings using a space delimiter
	input_values := strings.Split(input, " ")
	// Convert the first slice element to an integer and store it in N
	N, _ := strconv.Atoi(input_values[0])
	// Convert the second slice element to an integer and store it in T
	T, _ := strconv.Atoi(input_values[1])
	// Initialize an array A of size N
	A := make([]int, N)
	// Read integer values from stdin and store them in array A
	for i := 0; i < N; i++ {
		fmt.Println("Enter the", i+1, "element of array A")
		// Read the next line of input from stdin
		input, _ := reader.ReadString('\n')
		// Split the input string into a slice of strings using a space delimiter
		input_values := strings.Split(input, " ")
		// Convert the first slice element to an integer and store it in A[i]
		A[i], _ = strconv.Atoi(input_values[0])
	}
	// Initialize variable m with the minimum value among the first two elements of array A
	m := A[0]
	if A[1] < m {
		m = A[1]
	}
	// Initialize a vector B of size N
	B := make([]int, N)
	// Set the first element of vector B with the difference between the second element of array A and the initialized value of m
	B[1] = A[1] - m
	// Iterate through the remaining elements of array A starting from the third one
	for i := 2; i < N; i++ {
		// Update the value of m with the minimum value between it and the current element of array A
		if A[i] < m {
			m = A[i]
		}
		// Set the current element of vector B with the difference between the current element of array A and the updated value of m
		B[i] = A[i] - m
	}
	// Print the output value to stdout
	fmt.Println(count(B, max(B)))
}

// count returns the number of times the value x appears in the slice
func count(slice []int, x int) int {
	// Initialize a variable to store the number of times x appears in the slice
	count := 0
	// Iterate through the slice
	for _, value := range slice {
		// If the current element of the slice is equal to x, increment the value of count
		if value == x {
			count++
		}
	}
	// Return the value of count
	return count
}

// max returns the maximum value in the slice
func max(slice []int) int {
	// Initialize a variable to store the maximum value in the slice
	max := slice[0]
	// Iterate through the slice
	for _, value := range slice {
		// If the current element of the slice is greater than the current value of max, update the value of max
		if value > max {
			max = value
		}
	}
	// Return the value of max
	return max
}

// END-OF-CODE

=======
	// Split the input string into two space-separated strings
	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimSuffix(input, "\r")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = strings.TrimSuffix(input, "\r\n")
	input = strings.TrimSuffix(input, "\n\r")
	input = 
>>>>>>> 98c87cb78a (data updated)
