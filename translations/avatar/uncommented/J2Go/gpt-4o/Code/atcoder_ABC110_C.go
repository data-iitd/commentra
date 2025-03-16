package main

import (
	"fmt"
	"strings"
)

func main() {
	var S, T string
	fmt.Scanln(&S)
	fmt.Scanln(&T)

	A := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}
	res := true

	for _, s := range A {
		sIdx := strings.Index(S, s)
		if sIdx < 0 {
			continue
		}
		t := string(T[sIdx])
		idx := 0

		for idx < len(S) {
			if strings.Index(S[idx:], s) >= 0 {
				if strings.Index(T[idx:], t) < 0 || strings.Index(S[idx:], s) != strings.Index(T[idx:], t) {
					res = false
					break
				} else {
					idx = strings.Index(S[idx:], s) + idx + 1
				}
			} else if strings.Index(T[idx:], t) >= 0 {
				res = false
				break
			} else {
				break
			}
		}
		if !res {
			break
		}
	}

	if res {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
