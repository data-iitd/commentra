
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
	for i := 0; i < len(s); i++ {
		if i%2 == 0 {
			switch s[i] {
			case 'R', 'U', 'D':
				break
			default:
				flag = true
				break
			}
		} else {
			switch s[i] {
			case 'L', 'U', 'D':
				break
			default:
				flag = true
				break
			}
		}
	}
	if flag {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

