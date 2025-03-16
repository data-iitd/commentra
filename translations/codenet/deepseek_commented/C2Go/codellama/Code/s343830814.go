package main

import (
	"fmt"
	"strings"
)

func main() {
	var buf [512]byte
	var len int

	// Step 3: Read input from stdin
	fmt.Scanf("%s", &buf)

	// Step 4: Calculate the length of the input
	len = len(buf)

	// Step 5: Print the first character, the length minus 3, and the second last character of the input
	fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
}

