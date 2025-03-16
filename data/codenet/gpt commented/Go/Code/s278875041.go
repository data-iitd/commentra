package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a variable to hold the input string
	var a string
	
	// Read input from the user and store it in variable 'a'
	fmt.Scan(&a)
	
	// Replace all occurrences of '1' with '0' in the input string
	tmp := strings.Replace(a, "1", "0", -1)
	
	// Replace all occurrences of '9' with '1' in the modified string
	b := strings.Replace(tmp, "9", "1", -1)
	
	// Replace all occurrences of '0' with '9' in the second modified string
	ans := strings.Replace(b, "0", "9", -1)
	
	// Print the final transformed string
	fmt.Println(ans)
}
