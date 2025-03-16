
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var str, tmp, p string
	var slen, plen int
	var i, j int
	var flag bool

	// Read two strings from the user
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str = scanner.Text()
	scanner.Scan()
	p = scanner.Text()

	// Duplicate and concatenate the string
	tmp = str
	str = str + tmp

	// Calculate the lengths of the strings
	slen = len(str)
	plen = len(p)

	// Initialize flag to 0 (not found)
	flag = false

	// Check if the pattern exists in the concatenated string
	for i = 0; i < slen-plen; i++ {
		if strings.HasPrefix(str[i:i+plen], p) {
			flag = true
		}
	}

	// Output the result
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

