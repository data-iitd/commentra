package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Reading the number of strings and the array of strings
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of strings")
	n, _ := reader.ReadString('\n')
	n = strings.TrimSpace(n)
	n_int, _ := strconv.Atoi(n)
	ss := make([]string, n_int)
	for i := 0; i < n_int; i++ {
		fmt.Println("Enter the string")
		ss[i], _ = reader.ReadString('\n')
		ss[i] = strings.TrimSpace(ss[i])
	}

	// Reading the pattern array and the target character
	fmt.Println("Enter the pattern")
	cc, _ := reader.ReadString('\n')
	cc = strings.TrimSpace(cc)
	cc = strings.ToLower(cc)
	fmt.Println("Enter the target character")
	c, _ := reader.ReadString('\n')
	c = strings.TrimSpace(c)
	c = strings.ToLower(c)
	c_ = strings.ToUpper(c)
	a := c == 'a'
	a_ := strings.ToUpper(string(a))

	// Array to mark positions in cc that match any string in ss
	lucky := make([]bool, len(cc))

	// Finding lucky positions and updating characters based on the target character c
	for j := 0; j < len(cc); j++ {
		for i := 0; i < n_int; i++ {
			l := len(ss[i])
			if len(cc)-j >= l && strings.Compare(cc[j:], ss[i]) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Updating characters in cc based on the lucky positions and target character c
	for j := 0; j < len(cc); j++ {
		if lucky[j] {
			if cc[j] == c {
				cc[j] = a_
			} else {
				cc[j] = c_
			}
		}
	}

	// Printing the modified cc array
	fmt.Println(cc)
}

