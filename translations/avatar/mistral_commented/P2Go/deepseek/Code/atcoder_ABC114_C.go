package main

import (
	"fmt"
	"strconv"
)

func aaa(n int) int {
	if n > N {
		return 0
	}

	ans := 0
	if set := strconv.Itoa(n); set == "753" {
		ans = 1
	}

	for _, i := range []rune{'7', '5', '3'} {
		ans += aaa(n*10 + int(i-'0'))
	}

	return ans
}

func main() {
	var N int
	fmt.Scan(&N)
	fmt.Println(aaa(0))
}

