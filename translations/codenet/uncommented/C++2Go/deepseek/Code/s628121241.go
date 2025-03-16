package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b % a, a)
}

func main() {
	var R int
	fmt.Scan(&R)
	if R < 1200 {
		fmt.Println("ABC")
	} else if R >= 2800 {
		fmt.Println("AGC")
	} else {
		fmt.Println("ARC")
	}
}

