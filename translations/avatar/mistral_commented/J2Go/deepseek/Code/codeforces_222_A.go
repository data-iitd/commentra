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
	n := parseInt(scanner.Text())
	scanner.Scan()
	k := parseInt(scanner.Text())

	l, c := 0, 1

	for i := 0; i < n; i++ {
		scanner.Scan()
		a := parseInt(scanner.Text())

		if a == l {
			c += 1
		} else {
			c = 1
		}

		l = a
	}

	if c+k > n {
		fmt.Println(n - c)
	} else {
		fmt.Println(-1)
	}
}

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

