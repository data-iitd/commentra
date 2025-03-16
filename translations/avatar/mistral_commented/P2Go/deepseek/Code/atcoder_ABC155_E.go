package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func main() {
	// Read input string 's'
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Initialize variables 'pp' and 'na'
	pp := 0
	na := 0

	// Iterate through each character in the input string 's'
	for i := len(s) - 1; i >= 0; i-- {
		c := s[i]
		cc := na + int(c-'0')
		na = 0

		// Update 'pp' based on the current character value 'cc'
		if cc <= 4 {
			pp += cc
		} else {
			// If current character is the last character, add 1 to 'pp'
			if i == 0 {
				pp += 1
			} else {
				// Otherwise, add 10 - 'cc' to 'pp'
				pp += 10 - cc
			}
		}
	}

	// Print the result 'pp'
	fmt.Println(pp)
}
