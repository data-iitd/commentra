

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define possible input methods: clipboard, file, key
var inputMethods = []string{"clipboard", "file", "key"}
// Indicate which input method to use, starting with 'clipboard'
var usingMethod = 0
var inputMethod = inputMethods[usingMethod]

// Define a lambda function to take integer inputs in space-separated format
var IN = func() []int {
	data, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	dataBytes := bytes.TrimSpace(data)
	sp := bytes.Split(dataBytes, []byte{' '})
	res := make([]int, len(sp))
	for i, v := range sp {
		res[i] = int(v[0] - '0')
	}
	return res
}

// Define a modulo value
var mod = 1000000007

// Main function for base case
func main_b() {
	// Take input string
	s := string(IN()[0])
	// Initialize pp and na to 0
	pp, na := 0, 0
	// Iterate over the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		cc := na + int(s[i]-'0')
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
	}
	// Print the result
	fmt.Println(pp)
}

// Main function for general case
func main() {
	s := string(IN()[0])
	pmin, mmin := 1000, 0
	s = "0" + s
	// Iterate over the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		v := int(s[i] - '0')
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin, mmin = npmin, nmmin
	}
	// Return the minimum of pmin and mmin
	return min(pmin, mmin)
}

// Function to print values if in test mode
func pa(v interface{}) {
	if isTest {
		fmt.Println(v)
	}
}

// Function to read input from clipboard if running on iOS
func input_clipboard() {
	// Implement the logic to read input from clipboard
}

// Main execution block
func main() {
	if inputMethod == inputMethods[0] {
		input_clipboard()
	} else if inputMethod == inputMethods[1] {
		file, _ := os.Open("inputFile.txt")
		defer file.Close()
		os.Stdin = file
	}
	ret := main()
	if ret!= nil {
		fmt.Println(ret)
	}
}

// Function to get the minimum value
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

