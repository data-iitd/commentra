package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n := toInt(scanner.Text())
	a := make([]int, n)
	r := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i] = toInt(scanner.Text())
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

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

