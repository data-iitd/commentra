package main

import (
	"fmt"
	"strings"
)

func main() {
	var c string
	var ans strings.Builder

	fmt.Scan(&c)
	for _, char := range c {
		if char != 'B' {
			ans.WriteRune(char)
		} else {
			// Remove the last character if it exists
			if ans.Len() > 0 {
				ans.Truncate(ans.Len() - 1)
			}
		}
	}
	fmt.Println(ans.String())
}

// <END-OF-CODE>
