package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	c := make([]byte, n)
	p := 'a'

	for i := 0; i < 4; i++ {
		for j := i; j < n; j += 4 {
			c[j] = byte(p)
			p++
		}
	}

	for i := 0; i < n; i++ {
		fmt.Print(string(c[i]))
	}
}

