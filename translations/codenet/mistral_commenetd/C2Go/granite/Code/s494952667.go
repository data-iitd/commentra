
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
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	len := len(str)
	fmt.Printf("Reversed string: ")
	for i := len - 1; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}

