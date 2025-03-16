package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	var n int
	var str, a, b string

	// Reading an integer input which represents the length of the string
	fmt.Scan(&n)
	
	// Consuming the newline character after the integer input
	_, _ = reader.ReadString('\n')

	// Reading the actual string input
	str, _ = reader.ReadString('\n')

	// Loop to construct the first half of the string
	for i := 0; i < n/2; i++ {
		a += string(str[i]) // Appending characters from the first half of the string to 'a'
	}

	// Checking if the string is made up of two identical halves
	if str == a+a {
		fmt.Println("Yes") // If true, print "Yes"
	} else {
		fmt.Println("No") // If false, print "No"
	}
}
