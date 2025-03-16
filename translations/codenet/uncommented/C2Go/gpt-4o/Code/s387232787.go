package main

import (
	"fmt"
	"strings"
)

func main() {
	c := make([]int, 26)
	var str string

	for {
		_, err := fmt.Scan(&str)
		if err != nil {
			break
		}
		for _, p := range str {
			if p >= 'a' && p <= 'z' {
				c[p-'a']++
			} else if p >= 'A' && p <= 'Z' {
				c[p-'A']++
			}
		}
	}

	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

// <END-OF-CODE>
