package main

import (
	"fmt"
	"strconv"
)

var N int

func aaa(n int) int {
	if n > N {
		return 0
	}

	ans := 0
	if setEqual(strconv.Itoa(n), []rune{'7', '5', '3'}) {
		ans = 1
	}

	for _, i := range []rune{'7', '5', '3'} {
		ans += aaa(n*10 + int(i-'0')) // Convert rune to int and add to n
	}

	return ans
}

func setEqual(s string, chars []rune) bool {
	charSet := make(map[rune]struct{})
	for _, c := range chars {
		charSet[c] = struct{}{}
	}

	for _, c := range s {
		delete(charSet, c)
	}

	return len(charSet) == 0 && len(s) == len(chars)
}

func main() {
	fmt.Scan(&N) // User inputs an integer value `N`
	fmt.Println(aaa(0)) // Call the function with argument `0` and print the result
}

// <END-OF-CODE>
