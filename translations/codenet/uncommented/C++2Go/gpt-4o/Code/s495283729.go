package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	flag := 0

	for i := 0; i < len(s); i++ {
		if i%2 == 0 {
			switch s[i] {
			case 'R', 'U', 'D':
				// valid characters for even indices
			default:
				flag = 1
			}
		} else {
			switch s[i] {
			case 'L', 'U', 'D':
				// valid characters for odd indices
			default:
				flag = 1
			}
		}
	}

	if flag == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
