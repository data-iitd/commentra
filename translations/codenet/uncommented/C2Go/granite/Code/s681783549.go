
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
	for i := 0; i < len(text)-1; i++ {
		if string(text[i]) == "A" && string(text[i+1]) == "C" {
			fmt.Println("Yes")
			return
		}
	}
	fmt.Println("No")
}

