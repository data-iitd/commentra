package main

import "fmt"

func main() {
	// Read a line of input, split it into parts, and convert each part to an integer
	var n, m int
	fmt.Scan(&n, &m)

	// Read a list of integers from input
	var lst []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		lst = append(lst, x)
	}

	// Initialize a dictionary to count occurrences of each integer in the list
	l := make(map[int]int)

	// Count the occurrences of each integer in the list
	for i := 0; i < n; i++ {
		if _, ok := l[lst[i]]; !ok {
			// If the integer is not in the dictionary, add it with a count of 1
			l[lst[i]] = 1
		} else {
			// If the integer is already in the dictionary, increment its count
			l[lst[i]] += 1
		}
	}

	// Initialize the result variable to store the final count
	res := 0

	// Calculate the result based on the occurrences of integers
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// If the current integer appears more than once
			res += n - i - l[lst[i]] // Add the number of valid pairs
			l[lst[i]] -= 1           // Decrease the count of this integer
		} else {
			// If the current integer appears only once
			res += n - i - 1 // Add the number of valid pairs for unique integers
		}
	}

	// Print the final result
	fmt.Println(res)
}

