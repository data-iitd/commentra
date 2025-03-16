package main

import (
	"fmt"
	"strconv"
)

var N int

func aaa(n string) int {
	num, _ := strconv.Atoi(n)
	if num > N {
		return 0
	}
	ans := 0
	if setEqual(n) {
		ans = 1
	}
	for _, i := range "753" {
		ans += aaa(n + string(i))
	}
	return ans
}

func setEqual(n string) bool {
	set := make(map[rune]struct{})
	for _, char := range n {
		set[char] = struct{}{}
	}
	return len(set) == 3 && set['7'] == struct{}{} && set['5'] == struct{}{} && set['3'] == struct{}{}
}

func main() {
	fmt.Scan(&N)
	fmt.Println(aaa("0"))
}

// <END-OF-CODE>
