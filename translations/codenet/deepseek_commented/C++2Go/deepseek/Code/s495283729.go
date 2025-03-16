package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	flag := 0
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
				flag = 1
				break
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
