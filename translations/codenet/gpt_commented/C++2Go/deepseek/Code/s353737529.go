package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	if n == 0 {
		fmt.Println("0")
		return
	}

	s := ""
	for n != 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}
		n -= int(math.Abs(float64(n % 2)))
		n /= -2
	}

	// Reverse the string to get the correct binary representation
	s = strings.Reverse(s)

	fmt.Println(s)
}

