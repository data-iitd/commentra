package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var str, com string
	var T map[string]bool

	fmt.Scanf("%d", &n)
	T = make(map[string]bool)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s%s", &com, &str)
		if com[0] == 'i' {
			T[str] = true
		} else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

