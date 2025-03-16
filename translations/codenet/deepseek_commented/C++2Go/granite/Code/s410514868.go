
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Reading the input values for n and k, and the string s
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d %d\n", &n, &k)
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]

	// Initializing L with the first character of s, and ans, cnt to zero
	L := s[0]
	cnt := 0

	// Loop through the string starting from the second character
	for i := 1; i < n; i++ {
		// If the current character is the same as L, increment cnt
		if L == s[i] {
			cnt++
		} else {
			// Update L to the new character, add cnt to ans, increment ans2, and reset cnt
			L = s[i]
			ans += cnt
			ans2++
			cnt = 0
		}
	}

	// Add the final count to ans and increment ans2
	ans += cnt
	ans2++

	// Calculate the output as ans + min(2*k, ans2-1) and print it
	fmt.Println(ans + min(2*k, ans2-1))
}

