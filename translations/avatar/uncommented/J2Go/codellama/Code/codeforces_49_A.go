
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)
	length := len(s)
	ch := ' '
	for i := length - 1; i >= 0; i-- {
		if s[i] != ' ' && s[i] != '?' {
			ch = s[i]
			break
		}
	}
	ch = strings.ToLower(string(ch))
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

