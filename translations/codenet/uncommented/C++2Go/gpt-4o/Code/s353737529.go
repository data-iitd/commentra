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

	// Reverse the string
	reversed := reverse(s)
	fmt.Println(reversed)
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
