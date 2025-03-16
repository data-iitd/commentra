package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Take an integer 'n' as input
	var n int
	fmt.Fscan(reader, &n)
	
	// Take two lists 's' and 't' of length 'n' as input
	s := make([]rune, n)
	t := make([]rune, n)
	
	// Read 's'
	sInput, _ := reader.ReadString('\n')
	for i := 0; i < n; i++ {
		s[i] = rune(sInput[i])
	}
	
	// Read 't'
	tInput, _ := reader.ReadString('\n')
	for i := 0; i < n; i++ {
		t[i] = rune(tInput[i])
	}
	
	// Check if both lists 's' and 't' are equal or not
	if string(s) == string(t) {
		// If they are equal, print the value of 'n'
		fmt.Println(n)
	} else {
		// Initialize a counter 'cnt' to store the length of the longest common substring
		cnt := 0
		
		// Iterate through all possible substrings of 's' starting from the first character
		for i := 0; i < n; i++ {
			// Iterate through all possible substrings of 't' starting from the first character
			for j := 0; j < n - i; j++ {
				// Check if the substring of 's' starting from index 'i+j' is equal to the substring of 't' starting from index 'j'
				if s[i + j] != t[j] {
					// If they are not equal, break the inner loop and move to the next substring of 's'
					break
				}
				
				// If they are equal and we have reached the end of the substring of 's', update the value of 'cnt'
				if j == n - i - 1 {
					cnt = n - i
				}
			}
		}
		
		// If 's' and 't' have no common substring, 'cnt' will be 0. In that case, print 2*n
		if cnt == 0 {
			fmt.Println(2 * n)
		} else {
			fmt.Println(2 * n - cnt)
		}
	}
}
