package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	
	var input string
	fmt.Scan(&input)
	m := strings.Split(input, " ")
	
	counts := make(map[string]int)
	for _, value := range m {
		counts[value]++
	}
	
	possible := true
	for _, count := range counts {
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

// <END-OF-CODE>
