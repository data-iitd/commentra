<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"strings"
)

func main() {
	// Declare two string variables, s and t
	var s, t string

	// Read a string from the standard input and store it in s
	fmt.Scanln(&s)

	// Assign the first character of s to t
	t = s[0:1]

	// Append the size of s minus 2 to t
	t += fmt.Sprintf("%d", len(s)-2)

	// Append the last character of s to t
	t += s[len(s)-1:]

	// Print the modified string t
	fmt.Println(t)
}

