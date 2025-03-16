
package main

import (
	"fmt"
	"math"
	"strconv"
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

		n -= n % 2
		n /= -2
	}

	s = strings.Reverse(s)
	fmt.Println(s)
}

