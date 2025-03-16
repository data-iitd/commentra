package main

import (
	"fmt"
)

func main() {
	var str [21]byte
	var len int

	// Read input string
	n, _ := fmt.Scanf("%s", &str)
	len = n

	// Print the string in reverse
	for i := len - 1; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}
