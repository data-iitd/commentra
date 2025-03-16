package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)

	vo := []rune{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'}
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] == ' ' || a[i] == '?' {
			continue
		} else {
			for _, v := range vo {
				if a[i] == byte(v) {
					fmt.Println("YES")
					return
				}
			}
			fmt.Println("NO")
			return
		}
	}
}

// <END-OF-CODE>
