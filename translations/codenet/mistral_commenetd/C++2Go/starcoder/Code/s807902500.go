
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare two string variables s and t to store user input.
	var s, t string

	// Read user input and store it in variables s and t respectively.
	fmt.Scanln(&s, &t)

	// Concatenate the string s with itself and store the result back in s.
	s += s

	// Use the fmt.Println() function to print the result to the console.
	fmt.Println(strings.Contains(s, t))
	// Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".

	// 