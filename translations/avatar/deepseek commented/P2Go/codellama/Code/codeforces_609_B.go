
package main

import "fmt"

func main() {
	// Read the values of n and m
	var n, m int
	fmt.Scan(&n, &m)
	// Read the list of elements
	var lst []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		lst = append(lst, x)
	}
	// Initialize a dictionary to store the frequency of elements
	l := make(map[int]int)
	// Populate the dictionary with the frequency of each element in the list
	for i := 0; i < n; i++ {
		if _, ok := l[lst[i]]; !ok {
			l[lst[i]] = 1
		} else {
			l[lst[i]] += 1
		}
	}
	// Initialize the result variable to store the final result
	res := 0
	// Iterate over the list to calculate the result
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// Calculate the number of pairs that can be formed with the current element
			res += n - i - l[lst[i]]
			// Decrement the frequency of the current element in the dictionary
			l[lst[i]] -= 1
		} else {
			// If the frequency is not greater than 1, calculate the number of pairs
			res += n - i - 1
		}
	}
	// Print the final result
	fmt.Println(res)
}

