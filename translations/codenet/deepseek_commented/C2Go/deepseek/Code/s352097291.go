package main

import (
	"fmt"
	"strings"
)

func main() {
	var c, ans string
	fmt.Scan(&c)

	for _, char := range c {
		if char != 'B' {
			ans += string(char)
		} else {
			ans = ans[:len(ans)-1]
		}
	}

	fmt.Println(ans)
}

