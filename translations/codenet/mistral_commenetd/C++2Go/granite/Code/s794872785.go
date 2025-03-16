
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize variables
	maxsize := 0
	maxcnt := 0
	ans_num := -1
	ans_num2 := -1
	str_v := make([]string, 0) // Vector to store strings read from input

	// Read strings from input
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Push the string into the vector
		str_v = append(str_v, scanner.Text())
		// Update maxsize if the current string is larger
		if len(str_v[len(str_v)-1]) > maxsize {
			maxsize = len(str_v[len(str_v)-1])
			ans_num = len(str_v) - 1
		}
	}

	// Find the string with maximum occurrences in the vector
	for i := 0; i < len(str_v); i++ {
		cnt := 0
		// Count the occurrences of the current string in the vector
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++
			}
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if cnt > maxcnt {
			maxcnt = cnt
			ans_num2 = i
		}
	}

	// Print the answer
	fmt.Println(str_v[ans_num2], str_v[ans_num])
}

// End of code