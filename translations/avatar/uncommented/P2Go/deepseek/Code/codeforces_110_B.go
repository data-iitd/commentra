package main

import (
	"fmt"
)

func main() {
	const LUCKY = "abcd"
	var n int
	fmt.Scan(&n)
	s := ""
	for i := 0; i < n; i++ {
		s += string(LUCKY[i%4])
	}
	fmt.Println(s)
}

