
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

	result := ""
	i := 0

	for i < len(s) {
		if s[i] == '.' {
			result += "0"
		} else {
			i++
			if s[i] == '.' {
				result += "1"
			} else {
				result += "2"
			}
		}
		i++
	}

	fmt.Println(result)
}

