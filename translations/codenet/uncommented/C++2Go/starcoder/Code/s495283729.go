package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := strings.TrimSpace(os.Args[1])
	for i := 0; i < len(s); i++ {
		if i%2 == 0 {
			switch s[i] {
			case 'R':
				break
			case 'U':
				break
			case 'D':
				break
			default:
				fmt.Println("No")
				return
			}
		} else {
			switch s[i] {
			case 'L':
				break
			case 'U':
				break
			case 'D':
				break
			default:
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

