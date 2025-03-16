<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scanf("%s %s", &s, &t) // Read two strings from standard input

	// Concatenate s with itself to double its length
	s += s

	// Check if t is a substring of the doubled s
	// If found, find returns the position; otherwise, it returns -1
	// Convert the result to a boolean for easy printing
	fmt.Println(strings.Contains(s, t))
}

