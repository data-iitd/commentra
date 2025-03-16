package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	var flag int
	for i := 0; i < len(s); i++ {
		if i%2 == 0 {
			switch s[i] {
			case 'R', 'U', 'D':
				break
			default:
				flag = 1
				break
			}
		} else {
			switch s[i] {
			case 'L', 'U', 'D':
				break
			default:
				flag = 1
				break
			}
		}
	}
	if flag == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

