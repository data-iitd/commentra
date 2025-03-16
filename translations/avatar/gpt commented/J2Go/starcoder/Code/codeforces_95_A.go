package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read the number of strings
	var n int
	fmt.Scanf("%d\n", &n)

	// Read each string and convert it to a character array
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		s := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
		ss[i] = []rune(s)
	}

	// Read the character array to be modified
	cc := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
	m := len(cc)

	// Read the character to be replaced
	c := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
	c_ := strings.ToUpper(c)

	// Determine the character to replace with
	a := c == 'a'? 'b' : 'a'
	a_ := strings.ToUpper(a)

	// Array to track positions that can be marked as lucky
	lucky := make([]bool, m)

	// Loop through each position in the character array
	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			// Check if the substring matches and mark lucky positions
			if m-j >= l && strings.Compare(string(cc[j:j+l]), string(ss[i])) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Replace characters in the original array based on lucky positions
	for j := 0; j < m; j++ {
		if lucky[j] {
			// Replace with the determined character based on case
			if strings.ToLower(string(cc[j])) == c {
				cc[j] = strings.ToUpper(string(cc[j])) == a_? a : a_
			} else {
				cc[j] = strings.ToUpper(string(cc[j])) == c_? c : c_
			}
		}
	}

	// Print the modified character array
	fmt.Println(string(cc))
}

