package main

import (
	"fmt"
)

func main() {
	var s, t [4]byte
	fmt.Scanf("%s", &s)
	fmt.Scanf("%s", &t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
	fmt.Println(hit)
}

// <END-OF-CODE>
