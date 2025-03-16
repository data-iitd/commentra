
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
	for i, v := range strings.Split(text, "") {
		fmt.Print(v)
	}
	fmt.Println()
}

