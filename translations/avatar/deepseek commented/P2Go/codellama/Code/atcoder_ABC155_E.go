
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define possible input methods: clipboard, file, key
var input_methods = []string{"clipboard", "file", "key"}

// Indicate which input method to use, starting with 'clipboard'
var using_method = 0
var input_method = input_methods[using_method]

// Define a lambda function to take integer inputs in space-separated format
var IN = func() []int {
	var l []int
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	for _, v := range strings.Split(s.Text(), " ") {
		i, _ := strconv.Atoi(v)
		l = append(l, i)
	}
	return l
}

// Define a modulo value
var mod = 1000000007

// Main function for base case
func main_b() {
	// Take input string
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	s = s.Text()
	// Initialize pp and na to 0
	pp := 0
	na := 0
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
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	s = s.Text()
	s = "0" + s
	pmin := 1000
	mmin := 0
	// Iterate over the string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		v, _ := strconv.Atoi(string(s[i]))
		npmin := min(pmin+10-(v+1), mmin+10-v)
		nmmin := min(pmin+v+1, mmin+v)
		pmin = npmin
		mmin = nmmin
	}
	// Return the minimum of pmin and mmin
	return min(pmin, mmin)
}

// Check if the script is running in test mode
var isTest = false

// Function to print values if in test mode
func pa(v interface{}) {
	if isTest {
		fmt.Println(v)
	}
}

// Function to read input from clipboard if running on iOS
func input_clipboard() {
	input_text := bufio.NewScanner(os.Stdin)
	input_text.Scan()
	input_l := strings.Split(input_text.Text(), "\n")
	for _, l := range input_l {
		fmt.Println(l)
	}
}

// Main execution block
func main() {
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1] == "test" {
			isTest = true
		}
	}
	if os.Args[0] == "main" {
		if os.Args[1]