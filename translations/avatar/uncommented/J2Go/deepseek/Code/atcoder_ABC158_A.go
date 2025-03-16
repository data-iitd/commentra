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

	if containsA(s) && containsB(s) {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}
}

func containsA(s string) bool {
	for _, char := range s {
		if char == 'A' {
			return true
		}
	}
	return false
}

func containsB(s string) bool {
	for _, char := range s {
		if char == 'B' {
			return true
		}
	}
	return false
}

