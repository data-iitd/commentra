package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)

	for i := 'a'; i <= 'z'; i++ {
		a := 0
		for j := 0; j < len(s); j++ {
			if rune(s[j]) == i {
				a++
			}
		}
		if a == 0 {
			fmt.Println(string(i))
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

// <END-OF-CODE>
