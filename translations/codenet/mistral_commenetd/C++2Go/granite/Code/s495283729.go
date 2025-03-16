
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	flag := false
	for i, char := range s {
		if i%2 == 0 {
			switch char {
			case 'R':
				continue
			case 'U':
				continue
			case 'D':
				continue
			default:
				flag = true
				break
			}
		} else {
			switch char {
			case 'L':
				continue
			case 'U':
				continue
			case 'D':
				continue
			default:
				flag = true
				break
			}
		}
	}

	if!flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
