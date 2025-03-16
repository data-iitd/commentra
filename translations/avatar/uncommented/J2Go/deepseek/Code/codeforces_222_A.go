package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var l, c int
	for i := 0; i < n; i++ {
		scanner.Scan()
		a := scanner.Int()
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
