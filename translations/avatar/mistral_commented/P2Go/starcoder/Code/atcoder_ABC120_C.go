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
		// If so, print 0 and exit
		fmt.Println(0)
		return
	}

	// Count the occurrences of each character in the string
	a := make(map[rune]int)
	for _, v := range s {
		a[v]++
	}

	// Calculate the answer
	ans := 0
	for _, v := range a {
		ans += v / 2
	}

	// Print the answer
	fmt.Println(ans)
}

