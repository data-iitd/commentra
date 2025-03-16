package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var m []string
	var input string
	fmt.Scan(&input)
	m = strings.Split(input, " ")

	possible := true
	mSet := make(map[string]int)

	for _, value := range m {
		mSet[value]++
	}

	for _, count := range mSet {
		if count >= n/2+1 {
			possible = false
			break
		}
	}

	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

