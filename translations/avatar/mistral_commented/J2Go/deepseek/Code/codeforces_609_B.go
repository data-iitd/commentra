package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a new Scanner object to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the first integer input n from the user
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)

	// Reading the second integer input m from the user
	scanner.Scan()
	m, _ := fmt.Sscanf(scanner.Text(), "%d", &m)

	// Creating an integer array arr of size n to store the input integers
	arr := make([]int, n)

	// Creating an integer array gen of size 11 to store the count of each integer occurrence
	gen := make([]int, 11)

	// Reading the input integers and storing them in the arr array
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i], _ = fmt.Sscanf(scanner.Text(), "%d", &arr[i])
		// Incrementing the count of the arr[i] in the gen array
		gen[arr[i]]++
	}

	// Calculating the answer
	var ans int64 = 0
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			// Skipping the case when i and k are equal to avoid double counting
			if i != k {
				// Multiplying the count of i and k and adding it to the answer
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	// Printing the answer divided by 2
	fmt.Println(ans / 2)
}
