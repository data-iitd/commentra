package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	s, _ := reader.ReadString('\n')

	for i := 'a'; i <= 'z'; i++ {
		a := 0
		for j := 0; j < len(s); j++ {
			if i == rune(s[j]) {
				a++
			}
		}
		if a == 0 {
			fmt.Println(string(i))
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

