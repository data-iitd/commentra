
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
	lastChar := byte(0)
	for i := len(s) - 1; i >= 0; i-- {
		if s[i]!='' && s[i]!= '?' {
			lastChar = s[i]
			break
		}
	}
	lastChar = byte(strings.ToLower(string(lastChar)))
	if lastChar == 'a' || lastChar == 'e' || lastChar == 'i' || lastChar == 'o' || lastChar == 'u' || lastChar == 'y' {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

