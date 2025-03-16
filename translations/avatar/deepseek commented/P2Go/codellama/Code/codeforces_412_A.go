
package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	// Input the number of elements (n) and the position index (k)

	var v string
	fmt.Scan(&v)
	// Input the string v

	var d = []string{"LEFT", "RIGHT"}
	// Define a list containing the directions "LEFT" and "RIGHT"

	var f bool
	if k-1 < n-k {
		f = true
	} else {
		f = false
	}
	// Determine the boolean value of f based on the comparison between k-1 and n-k

	var m int
	if k-1 < n-k {
		m = k - 1
	} else {
		m = n - k
	}
	// Assign m as the minimum of k-1 and n-k

	var a []string
	// Initialize an empty list a to store the sequence of actions

	for i := 0; i < m; i++ {
		a = append(a, d[1-f])
		// Append the opposite direction to a based on the value of f
	}

	for i := 0; i < len(v); i++ {
		a = append(a, "PRINT "+string(v[i]))
		a = append(a, d[f])
		// Iterate over the reversed string v with a step of 2*f-1, appending "PRINT" and the current character, followed by the direction f
	}

	for i := 0; i < len(a)-1; i++ {
		fmt.Println(a[i])
		// Print all elements in a except the last one, separated by newlines
	}
}

