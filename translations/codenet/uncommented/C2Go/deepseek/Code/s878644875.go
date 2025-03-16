package main

import (
	"fmt"
)

func main() {
	var s, t [3]rune
	fmt.Scan(&s)
	fmt.Scan(&t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
	fmt.Println(hit)
}

