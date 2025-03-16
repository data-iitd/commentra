

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
	vowels := "aeiouyAEIOUY"
	for i := len(text) - 1; i >= 0; i-- {
		if text[i] =='' || text[i] == '?' {
			continue
		} else {
			if strings.ContainsRune(vowels, rune(text[i])) {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
			break
		}
	}
}

