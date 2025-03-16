
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	for i := 'a'; i <= 'z'; i++ {
		a := 0
		for j := 0; j < len(s); j++ {
			if i == s[j] {
				a++
			}
		}
		if a == 0 {
			fmt.Println(i)
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

