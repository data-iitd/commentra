package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the product of all the counts of characters from 'b' to 'z'
func product(cnt []int) int {
	ans := 1
	for i := 1; i < len(cnt); i++ {
		ans *= cnt[i]
		ans %= int(math.Pow(10, 9) + 7)
	}
	return ans
}

func main() {
	// Read the number of characters
	n, _ := strconv.Atoi(os.Args[1])

	// Initialize a vector to count occurrences of each character (a-z)
	cnt := make([]int, 26)
	cnt[0] = 1
	s := make([]byte, n)

	// Read characters and count their occurrences
	for i := 0; i < n; i++ {
		s[i], _ = strconv.Atoi(string(os.Args[2+i]))
		cnt[s[i]-'a']++
	}

	ans := cnt[0]

	// Calculate the product of counts for all characters from 'b' to 'z'
	ans = product(cnt)

	// Output the final result, subtracting 1 to exclude the empty product case
	fmt.Println(ans - 1)
}

