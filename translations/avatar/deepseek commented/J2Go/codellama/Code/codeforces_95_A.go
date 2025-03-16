package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Reading the number of strings and the array of strings
	var n int
	fmt.Scan(&n)
	ss := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ss[i])
	}

	// Reading the pattern array and the target character
	var cc string
	fmt.Scan(&cc)
	c := cc[0]
	c_ := strings.ToUpper(string(c))
	a := "b"
	a_ := strings.ToUpper(a)

	// Array to mark positions in cc that match any string in ss
	lucky := make([]bool, len(cc))

	// Finding lucky positions and updating characters based on the target character c
	for j := 0; j < len(cc); j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if len(cc[j:]) >= l && strings.EqualFold(cc[j:j+l], ss[i]) {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Updating characters in cc based on the lucky positions and target character c
	for j := 0; j < len(cc); j++ {
		if lucky[j] {
			if strings.ToLower(string(cc[j])) == c {
				cc = strings.Replace(cc, string(cc[j]), a_, 1)
			} else {
				cc = strings.Replace(cc, string(cc[j]), c_, 1)
			}
		}
	}

	// Printing the modified cc array
	fmt.Println(cc)
}

