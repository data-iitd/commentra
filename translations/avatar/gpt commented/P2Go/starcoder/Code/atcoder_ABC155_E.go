package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the available input methods
var inputMethods = []string{"clipboard", "file", "key"}
var usingMethod = 0  // Index to select the input method
var inputMethod = inputMethods[usingMethod]  // Select the input method based on the index

// Define a lambda function for reading multiple integers from input
var IN = func() []int {
	var a []int
	for _, s := range strings.Split(readLine(), " ") {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}
	return a
}

func main() {
	// Read input string
	s := readLine()
	pp := 0  // Initialize the total score
	na := 0  // Initialize carry-over value

	// Process the string in reverse order
	for i, c := range s[::-1] {
		cc := na + int(c-'0')  // Calculate the current value with carry-over
		na = 0  // Reset carry-over for the next iteration

		// Determine how to update the total score based on the current value
		if cc <= 4 {
			pp += cc  // If the value is 4 or less, add it directly to the score
		} else {
			na = 1  // Set carry-over if the value exceeds 4
			if i == len(s)-1 {
				pp += 1  // If it's the last digit, add 1 to the score
			}
			pp += 10 - cc  // Add the difference to the score
	}

	fmt.Println(pp)  // Output the final score
}

func readLine() string {
	r := bufio.NewReader(os.Stdin)
	line, _ := r.ReadString('\n')
	return strings.TrimSpace(line)
}

