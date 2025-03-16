package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanln(&n)
	T := make(map[string]bool)
	for i := 0; i < n; i++ {
		var com, str string
		fmt.Scanln(&com, &str)
		if com == "i" {
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

