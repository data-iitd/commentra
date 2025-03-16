
package main

import (
	"fmt"
	"math"
	"strconv"
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
		n -= n % 2
		n /= -2
	}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	fmt.Println(s)
}

