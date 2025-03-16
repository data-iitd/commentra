package main

import "fmt"

func main() {
	// Declare two integer variables n and k
	var n, k int
	
	// Read two integers from standard input
	// n represents the total number of items, and k represents a threshold value
	fmt.Scanf("%d %d\n", &n, &k)

	// Check if k is less than or equal to half of n (rounded up)
	if k <= (n+n%2)/2 {
		// If the condition is true, print "YES"
		fmt.Println("YES")
	} else {
		// If the condition is false, print "NO"
		fmt.Println("NO")
	}
}
