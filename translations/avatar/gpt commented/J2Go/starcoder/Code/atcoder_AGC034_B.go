package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read the input string and replace occurrences of "BC" with "D"
	s := strings.Replace(fmt.Sprintln(in.ReadString()), "\n", "", -1)
	s = regexp.MustCompile("BC").ReplaceAllString(s, "D")

	// Initialize counters for 'A' and the result
	cnt := 0
	tmp := 0

	// Iterate through the modified string to count occurrences
	for _, c := range s {
		// Increment temporary counter for 'A'
		if c == 'A' {
			tmp++
		}
		// Add the count of 'A's to the result when 'D' is encountered
		if c == 'D' {
			cnt += tmp
		}
		// Reset the temporary counter for any other character
		if c!= 'A' && c!= 'D' {
			tmp = 0
		}
	}

	// Output the final count of valid pairs
	fmt.Fprintln(out, cnt)

	// Close the output writer
	out.Flush()
}

