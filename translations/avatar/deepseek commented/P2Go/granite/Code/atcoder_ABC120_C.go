
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Main function to solve the problem
func main() {
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = bytes.TrimSpace(s)
	
	// Check if all characters in the string are the same
	if len(bytes.Count(s, []byte{'a'})) == len(s) {
		fmt.Println(0)
		return
	}
	
	// Count the frequency of each character in the string
	a := make(map[byte]int)
	for _, c := range s {
		a[c]++
	}
	
	// Calculate the answer as twice the minimum frequency of any character
	ans := 0
	for _, v := range a {
		if v < ans || ans == 0 {
			ans = v
		}
	}
	ans *= 2
	
	// Print the answer and exit
	fmt.Println(ans)
}

// Entry point of the script
func main() {
	main()
}

