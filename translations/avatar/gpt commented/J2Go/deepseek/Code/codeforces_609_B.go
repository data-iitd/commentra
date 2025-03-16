package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements (n) and the maximum value (m)
	scanner.Scan()
	n := 0
	fmt.Sscan(scanner.Text(), &n)
	
	scanner.Scan()
	m := 0
	fmt.Sscan(scanner.Text(), &m)
	
	// Initialize an array to store the input values
	arr := make([]int, n)
	
	// Initialize a frequency array to count occurrences of each number from 1 to 10
	gen := make([]int, 11)
	
	// Read n integers from input and populate the arr and gen arrays
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i] = 0
		fmt.Sscan(scanner.Text(), &arr[i])
		gen[arr[i]]++
	}
	
	// Initialize a variable to hold the final answer
	var ans int64 = 0
	
	// Calculate the number of valid pairs (i, k) where i != k
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				// Add the product of the counts of i and k to the answer
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}
	
	// Since each pair (i, k) is counted twice, divide the result by 2
	fmt.Println(ans / 2)
}
