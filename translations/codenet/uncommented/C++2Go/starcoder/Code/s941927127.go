package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var W string
	fmt.Scanln(&W)
	sort.Strings(strings.Split(W, ""))
	for i := 0; i < len(W); i += 2 {
		if W[i]!= W[i+1] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

