package main

import (
	"fmt"
	"strings"
)

func main() {
	// Step 1: Reading the Input
	var s string
	fmt.Scan(&s)

	// Step 2: Calculating the Size of the String
	n := len(s)

	// Step 3: Initializing an Array to Count Character Frequencies
	v := make([]int, 26)

	// Step 4: Counting Character Frequencies
	for i := 0; i < n; i++ {
		v[s[i]-'a']++
	}

	// Step 5: Determining the Result
	ans := "Yes"
	for i := 0; i < 26; i++ {
		if v[i]%2 != 0 {
			ans = "No"
			break
		}
	}

	// Step 6: Outputting the Result
	fmt.Println(ans)
}

