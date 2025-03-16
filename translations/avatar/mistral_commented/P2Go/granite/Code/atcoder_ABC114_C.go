

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1]) // Read an integer value `N` from the user

	aaa := func(n int) int { // Define a function `aaa` that takes an integer argument `n`
		if n > N { // Check if the input integer `n` is greater than `N`
			return 0 // If it is, return 0
		}

		ans := 1 // Initialize `ans` to 1
		if set := map[string]bool{"7": true, "5": true, "3": true}; set[strconv.Itoa(n)[0:1]] { // Check if the first character of the string representation of the integer `n` is present in the map `set`
			ans = 0 // If it is, set `ans` to 0
		}

		for _, i := range []string{"7", "5", "3"} { // Iterate through each character in the slice `[]string{"7", "5", "3"}`
			ans += aaa(n + intValue(i)) // Call the function recursively with the argument `n + intValue(i)` and add the result to `ans`
		}

		return ans // Return the value of `ans`
	}

	fmt.Println(aaa(0)) // Call the function with argument `0` and print the result
}

func intValue(s string) int { // Define a function `intValue` that takes a string argument `s` and returns the integer value of the string
	i, _ := strconv.Atoi(s)
	return i
}

