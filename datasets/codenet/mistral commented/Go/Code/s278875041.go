// Importing required packages
package main

import (
	"fmt"
	"strings"
)

// Declaring a variable 'a' of type string
func main() {
	var a string

	// Reading a string input from the user using fmt.Scan()
	fmt.Scan(&a)

	// Declaring a temporary variable 'tmp' of type string
	tmp := strings.Replace(a, "1", "0", -1)

	// Replacing all occurrences of '1' with '0' in the string 'a'
	// and storing the result in the variable 'tmp'

	b := strings.Replace(tmp, "9", "1", -1)

	// Replacing all occurrences of '9' with '1' in the string 'tmp'
	// and storing the result in the variable 'b'

	ans := strings.Replace(b, "0", "9", -1)

	// Replacing all occurrences of '0' with '9' in the string 'b'
	// and storing the result in the variable 'ans'

	// Printing the final answer using fmt.Println()
	fmt.Println(ans)
}

// Printing the final answer
