package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	for n > 0 {
		n--
		var s string
		fmt.Scanln(&s)
		for {
			c := strings.Index(s, "Hoshino")
			if c == -1 {
				break
			}
			s = s[:c+6] + "a" + s[c+7:]
		}
		fmt.Println(s)
	}
}

// <END-OF-CODE>
