
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Read input string
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Check if all characters in the string are the same
	if len(strings.Split(s, "")) == 1 {
		fmt.Println(0)
		return
	}

	// Count the occurrences of each character in the string
	a := make(map[rune]int)
	for _, v := range s {
		a[v]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	ans := 0
	for _, v := range a {
		if ans == 0 || v < ans {
			ans = v
		}
	}
	fmt.Println(ans * 2)
}

// 