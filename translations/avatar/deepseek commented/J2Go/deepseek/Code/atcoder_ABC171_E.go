package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	a := make([]int, n)
	r := 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
		r ^= a[i]
	}

	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(r ^ a[i])
	}
	fmt.Println()
}

