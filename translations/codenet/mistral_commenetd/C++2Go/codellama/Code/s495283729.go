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
			case 'R':
			case 'U':
			case 'D':
			default:
				flag = 1
			}
		} else {
			switch s[i] {
			case 'L':
			case 'U':
			case 'D':
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

