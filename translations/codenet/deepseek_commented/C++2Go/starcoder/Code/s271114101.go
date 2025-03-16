<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare three integer variables 'a', 'b', and 'c'
	var a, b, c int

	// Read three integers from the standard input and store them in 'a', 'b', and 'c'
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a: ")
	text, _ := reader.ReadString('\n')
	a, _ = strconv.Atoi(strings.TrimSpace(text))
	fmt.Print("Enter b: ")
	text, _ = reader.ReadString('\n')
	b, _ = strconv.Atoi(strings.TrimSpace(text))
	fmt.Print("Enter c: ")
	text, _ = reader.ReadString('\n')
	c, _ = strconv.Atoi(strings.TrimSpace(text))

=======
package main

import "fmt"

func main() {
	// Include the fmt library for formatted I/O operations
	
	// Define the main function, which is the entry point of the program
	
	// Declare three integer variables 'a', 'b', and 'c'
	
	// Read three integers from the standard input and store them in 'a', 'b', and 'c'
	
>>>>>>> 98c87cb78a (data updated)
	// Check if any of the following conditions are true:
	// - a + b equals c
	// - b + c equals a
	// - a + c equals b
<<<<<<< HEAD
	if a+b == c || b+c == a || a+c == b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
=======
	
	// If any of these conditions are true, print "Yes". Otherwise, print "No".
>>>>>>> 98c87cb78a (data updated)
}

