package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	s := in.Text()

	if containsA, containsB := containsAB(s); containsA && containsB {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}
}

func containsAB(s string) (bool, bool) {
	return contains(s, 'A'), contains(s, 'B')
}

func contains(s string, char rune) bool {
	for _, c := range s {
		if c == char {
			return true
		}
	}
	return false
}

