

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

	if str[2] == str[3] {
		if str[4] == str[5] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

