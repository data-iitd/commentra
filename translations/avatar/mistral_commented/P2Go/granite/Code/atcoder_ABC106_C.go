
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read a single line from standard input as a string
func readLine() string {
	buf := new(bytes.Buffer)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to read a single integer from standard input
func readInt() int {
	res, err := strconv.Atoi(readLine())
	if err!= nil {
		panic(err)
	}
	return res
}

// Function to read a single float from standard input
func readFloat() float64 {
	res, err := strconv.ParseFloat(readLine(), 64)
	if err!= nil {
		panic(err)
	}
	return res
}

// Function to print a string with a newline character at the end
func println(s string) {
	fmt.Println(s)
}

// Main function
func main() {
	// Reading input string and number of occurrences of '1' required
	s := readLine()
	k := readInt()

	// Finding the length of the substring consisting only of '1's
	l := 0
	for _, c := range s {
		if c!= '1' {
			// If the length of the substring is greater than or equal to the required number of occurrences, return 1
			if l >= k {
				println("1")
				return
			}
			break
		}
		l++
	}

	// If the length of the substring is less than the required number of occurrences, return the character after the substring
	println(string(s[l]))
}

// End of code