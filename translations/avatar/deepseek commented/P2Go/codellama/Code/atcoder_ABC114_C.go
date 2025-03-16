
package main

import (
	"fmt"
	"strconv"
)

func aaa(n string) int {
	// Check if the integer value of `n` is greater than N. If it is, return 0
	if intN, _ := strconv.Atoi(n); intN > N {
		return 0
	}

	// Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
	ans := 1
	if setN := []byte(n); setN[0] != '7' || setN[1] != '5' || setN[2] != '3' {
		ans = 0
	}

	// Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
	for _, i := range "753" {
		ans += aaa(n + string(i))
	}

	// Return the value of `ans`
	return ans
}

func main() {
	// Take an integer input N
	fmt.Scan(&N)

	// Call the function `aaa` with the initial argument '0' and print the result
	fmt.Println(aaa("0"))
}

