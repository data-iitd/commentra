package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)

func main() {
	// Creating a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Initializing variables to hold parts of the input string
	var a, b, str string
	var n int

	// Reading an integer input which represents the length of the string
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	str = scanner.Text()

	// Loop to construct the first half of the string
	for i := 0; i < n/2; i++ {
		a = a + string(str[i]) // Appending characters from the first half of the string to 'a'
	}

	// Checking if the string is made up of two identical halves
	if str == a+a {
		fmt.Println("Yes") // If true, print "Yes"
	} else {
		fmt.Println("No") // If false, print "No"
	}
}

