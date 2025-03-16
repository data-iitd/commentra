
package main

import "fmt"

func main() {
	
	var n, i, j, q, sum int
	var x, y []int
	
	fmt.Scan(&n)  // Read the number of elements
	
	x = make([]int, n)  // Create an array x with n elements
	
	for i = 0; i < n; i++ {
		fmt.Scan(&x[i])  // Read the elements of array x
	}
	
	fmt.Scan(&q)  // Read the number of queries
	
	y = make([]int, q)  // Create an array y with q elements
	
	for i = 0; i < q; i++ {
		fmt.Scan(&y[i])  // Read the elements of array y
	}
	
	for i = 0; i < q; i++ {  // For each query
		for j = 0; j < n; j++ {  // Check each element in array x
			if y[i] == x[j] {  // If the query matches an element in x
				sum = sum + 1  // Increment the sum
				break  // Break out of the inner loop
			}
		}
	}
	
	fmt.Println(sum)  // Print the sum of matches
	
	// 