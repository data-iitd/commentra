
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
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	for i := 'a'; i <= 'z'; i++ {
		count := 0
		for _, char := range text {
			if char == i {
				count++
			}
		}
		if count == 0 {
			fmt.Println(string(i))
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}
