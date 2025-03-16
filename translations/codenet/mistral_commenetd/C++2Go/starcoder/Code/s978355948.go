
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function starts here
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Println("Enter the size of the array and the sum")
	// Read the first line of input from stdin
	input, _ := reader.ReadString('\n')
	// Split the input string into two space-separated strings
	input = strings.Split(input, " ")
	// Convert the first string into an integer and store it in N
	N, _ := strconv.Atoi(input[0])
	// Convert the second string into an integer and store it in X
	X, _ := strconv.Atoi(input[1])
	// Create a vector L of size N to store the elements
	L := make([]int, N)
	// Read elements of vector L from user input
	for i := 0; i < N; i++ {
		fmt.Println("Enter the element", i+1)
		// Read the next line of input from stdin
		input, _ := reader.ReadString('\n')
		// Convert the string into an integer and store it in L[i]
		L[i], _ = strconv.Atoi(input)
	}
	// Initialize variable i and d to zero
	i := 0
	d := 0
=======
	fmt.Print("Enter the size of the array: ")
	// Read the first line of input from stdin
	input, _ := reader.ReadString('\n')
	// Convert the string to a number
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter the sum: ")
	// Read the second line of input from stdin
	input, _ = reader.ReadString('\n')
	// Convert the string to a number
	X, _ := strconv.Atoi(strings.TrimSpace(input))

	// Create a vector L of size N to store the elements
	L := make([]int, N)

	// Read elements of vector L from user input
	for i := 0; i < N; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		// Read the next line of input from stdin
		input, _ = reader.ReadString('\n')
		// Convert the string to a number
		L[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Initialize variable i and d to zero
	i := 0
	d := 0

>>>>>>> 98c87cb78a (data updated)
	// Loop through the vector L until the sum d exceeds X
	for ; i < N && d <= X; i++ {
		// Add the current element of vector L to the sum d
		d += L[i]
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	// Print the index of the last element in the vector L that was added to the sum d
	fmt.Println(i + 1)
}

<<<<<<< HEAD
Translate the above Go code to Python and end with comment "
=======
>>>>>>> 98c87cb78a (data updated)
