package main

import (
	"fmt"
	"strconv"
)

func aaa(n string, N int) int {
	if intValue, _ := strconv.Atoi(n); intValue > N {
		return 0
	}
	ans := 0
	if set, _ := strconv.Atoi(n); set == 753 {
		ans = 1
	}
	for _, i := range "753" {
		ans += aaa(n+string(i), N)
	}
	return ans
}

func main() {
	var N int
	fmt.Scan(&N)
	fmt.Println(aaa("0", N))
}

