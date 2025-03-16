// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare two integer variables "n" and "k"
	var n, k int

	// Read the values of "n" and "k" from the standard input
	fmt.Scanf("%d %d\n", &n, &k)

	// Check if the value of "k" is less than or equal to the middle index of the slice "n"
	if k <= (n+n%2)/2 {
		// If the condition is true, print "YES" to the standard output
		fmt.Println("YES")
	} else {
		// If the condition is false, print "NO" to the standard output
		fmt.Println("NO")
	}
}

// End of the code
