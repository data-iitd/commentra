
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define possible input methods: clipboard, file, key
var inputMethods = []string{"clipboard", "file", "key"}
// Indicate which input method to use, starting with 'clipboard'
var usingMethod = 0
var inputMethod = inputMethods[usingMethod]

// Define a lambda function to take integer inputs in space-separated format
var IN = func() []int {
	var a []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Fields(scanner.Text()) {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}
	return a
}

// Define a modulo value
const mod = 1000000007

// Main function for base case
func mainB() {
	// Take input string
	var s string
	fmt.Scanln(&s)
	// Initialize pp and na to 0
	var pp, na int
	// Iterate over the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		c := s[i]
		cc := na + int(c) - '0'
		na = 0
		// If the sum is less than or equal to 4, add to pp
		if cc <= 4 {
			pp += cc
		} else {
			na = 1
			// If it's the last digit, add 1 to pp
			if i == 0 {
				pp += 1
			}
			pp += 10 - cc
	}
	// Print the result
	fmt.Println(pp)
}

// Main function for general case
func main() {
	var s string
	fmt.Scanln(&s)
	var pmin, mmin int
	s = "0" + s
	// Iterate over the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		c := s[i]
		v := int(c) - '0'
		npmin := min(pmin + 10 - (v + 1), mmin + 10 - v)
		nmmin := min(pmin + v + 1, mmin + v)
		pmin = npmin
		mmin = nmmin
	}
	// Return the minimum of pmin and mmin
	fmt.Println(min(pmin, mmin))
}

// Function to print values if in test mode
func pa(v int) {
	if isTest {
		fmt.Println(v)
	}
}

// Function to read input from clipboard if running on iOS
func inputClipboard() {
	var inputText string
	fmt.Scanln(&inputText)
	inputLines := strings.Split(inputText, "\n")
	for _, line := range inputLines {
		fmt.Scanln(&line)
	}
}

// Main execution block
func main() {
	if runtime.GOOS == "ios" {
		if inputMethod == inputMethods[0] {
			inputClipboard()
		} else if inputMethod == inputMethods[1] {
			os.Stdin = os.NewFile(0, os.DevNull)
		} else {
			return
		}
		isTest = true
	}
	main()
}

// Function to return the minimum of two values
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Check if the script is running in test mode
var isTest = false

