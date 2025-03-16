package main

import "fmt"

func main() {
	var n, m int // 1. Input Reading: Declare variables to store the number of sets and the maximum element value.
	var k, a int // Declare variables to store the number of elements in each set and individual elements.
	x := make([]int, 31) // 2. Array Initialization: Initialize an array to count occurrences of each element from 1 to 30.
	fmt.Scan(&n, &m) // Read the number of sets and the maximum element value.
	for i := 0; i < n; i++ { // 3. Nested Loops for Input: Loop through each set.
		fmt.Scan(&k) // Read the number of elements in the current set.
		for j := 0; j < k; j++ { // Loop through each element in the current set.
			fmt.Scan(&a) // Read an element.
			x[a]++ // Increment the count of the element in the array x.
		}
	}
	ans := 0 // 4. Counting Elements: Initialize a variable to store the count of elements that appear in every set.
	for i := 1; i <= m; i++ { // Loop through each element from 1 to m.
		if x[i] == n { // Check if the element appears in every set.
			ans++ // Increment the count if the condition is met.
		}
	}
	fmt.Println(ans) // 5. Output the Result: Print the final count of elements that appear in every set.
}

