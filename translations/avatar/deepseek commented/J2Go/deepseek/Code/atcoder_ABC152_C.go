package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	fmt.Println(solve())
}

func solve() int {
	// Create a Scanner object to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the integer N from the input
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	
	// Initialize an array of size N to store the integers
	arr := make([]int, N)
	
	// Read N integers from the input and store them in the array
	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Initialize a sum variable to 0
	sum := 0
	
	// Create a slice to store the integers in ascending order
	var q []int
	
	// Iterate through the array and add each element to the slice
	for i := 0; i < len(arr); i++ {
		q = append(q, arr[i])
		
		// Sort the slice to maintain the order
		sort.Ints(q)
		
		// Check if the current element is less than or equal to the smallest element in the slice
		if arr[i] <= q[0] {
			sum++
		}
	}
	
	// Return the sum
	return sum
}
