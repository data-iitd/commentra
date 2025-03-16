package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n) and the maximum value (m)
	n, _ := strconv.Atoi(in.Text())
	m, _ := strconv.Atoi(in.Text())

	// Initialize an array to store the input values
	arr := make([]int, n)

	// Initialize a frequency array to count occurrences of each number from 1 to 10
	gen := make([]int, 11) // gen[0] will remain unused

	// Read n integers from input and populate the arr and gen arrays
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(in.Text()) // Store the input value in arr
		gen[arr[i]]++                       // Increment the count of the corresponding number in gen
	}

	// Initialize a variable to hold the final answer
	ans := 0

	// Calculate the number of valid pairs (i, k) where i != k
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				// Add the product of the counts of i and k to the answer
				ans += gen[i] * gen[k]
			}
		}
	}

	// Since each pair (i, k) is counted twice, divide the result by 2
	fmt.Println(ans / 2)
}

