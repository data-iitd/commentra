
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	s := make([]byte, 0)  // Initialize a byte slice to store the input string
	x := true  // Initialize a boolean variable to track the result
	dt := make(map[byte]int)  // Initialize an empty map to store character frequencies

	// Read the input string and update the frequency count in the map
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s = scanner.Bytes()
		for _, v := range s {
			if _, ok := dt[v]; ok {
				dt[v]++
			} else {
				dt[v] = 1
			}
		}
	}

	cnt := 0  // Initialize a counter to keep track of characters with an odd frequency
	x = true  // Reset the boolean variable to track the result

	// Iterate over the items in the map to determine if there is more than one character with an odd frequency
	for key, value := range dt {
		if value%2!= 0 && cnt < 1 {
			cnt++
		} else if value%2!= 0 && cnt >= 1 {
			x = false
			break
		}
	}

	// Determine the output based on the value of cnt and the length of the input string
	if x {
		fmt.Println("First")  // Print "First" if there is at most one character with an odd frequency
	} else if!x && len(s)%2 == 0 {
		fmt.Println("Second")  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
	} else if!x && len(s)%2!= 0 {
		fmt.Println("First")  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
	}
}
