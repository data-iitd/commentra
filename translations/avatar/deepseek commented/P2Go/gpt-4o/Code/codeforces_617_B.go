package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take an input from the user and store it in variable 'a'
	var a string
	fmt.Scanln(&a)

	// Print the result based on the input
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		segments := strings.Split(strings.Trim(a, "0 "), "1")
		result := 1
		for _, segment := range segments {
			result *= len(segment) + 1
		}
		fmt.Println(result)
	}
}

// <END-OF-CODE>
