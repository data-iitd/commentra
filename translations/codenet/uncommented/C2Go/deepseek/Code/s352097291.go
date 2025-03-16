package main

import (
	"fmt"
	"strings"
)

func main() {
	var c, ans string
	fmt.Scanln(&c)
	for i := 0; i < len(c); i++ {
		if c[i] != 'B' {
			ans += string(c[i])
		} else {
			ans = ans[:len(ans)-1]
		}
	}
	fmt.Println(ans)
}
