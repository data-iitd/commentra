package main

import (
	"fmt"
	"strconv"
)

func aaa(n string, N int) int {
	// Convert the string `n` to an integer
	nInt, _ := strconv.Atoi(n)
	
	// Check if the integer value of `n` is greater than N. If it is, return 0
	if nInt > N {
		return 0
	}
	
	// Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
	ans := 0
	if set(n) == "753" {
		ans = 1
	}
	
	// Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
	for _, i := range "753" {
		ans += aaa(n + string(i), N)
	}
	
	// Return the value of `ans`
	return ans
}

func main() {
	var N int
	fmt.Scan(&N) // Take an integer input N
	
	// Call the function `aaa` with the initial argument '0' and print the result
	fmt.Println(aaa("0", N))
}
