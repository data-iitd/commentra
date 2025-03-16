package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var str, a, b string
	fmt.Scan(&n)
	fmt.Scan(&str)

	for i := 0; i < n/2; i++ {
		a += string(str[i])
	}

	if str == strings.Repeat(a, 2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

