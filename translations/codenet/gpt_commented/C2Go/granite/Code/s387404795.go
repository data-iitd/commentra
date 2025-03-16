
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare character arrays for input strings and temporary storage
	var str, tmp, p string
	var slen, plen int
	var i, j, flag int

	// Read two strings from standard input
	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadString('\n')
	str = strings.TrimSpace(str)
	p, _ = reader.ReadString('\n')
	p = strings.TrimSpace(p)

	// Copy the original string into a temporary variable and concatenate it with itself
	tmp = str
	str = str + tmp

	// Calculate the lengths of the concatenated string and the pattern string
	slen = len(str)
	plen = len(p)

	// Initialize a flag to indicate if the pattern is found
	flag = 0

	// Loop through the concatenated string to search for the pattern
	for i = 0; i < slen-plen; i++ {
		// Compare the substring of str with the pattern p
		if strings.Compare(str[i:i+plen], p) == 0 {
			flag = 1 // Set flag if a match is found
		}
	}

	// Output "Yes" if the pattern was found, otherwise output "No"
	if flag == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

