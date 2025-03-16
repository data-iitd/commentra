package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	r0 := make([]bool, n)
	for i := 0; i < n; i++ {
		r0[i] = false
	}
	r1 := make([]int, n)
	var nr1 int

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < m; i++ {
		scanner.Scan()
		a := scanner.Int()
		scanner.Scan()
		b := scanner.Int()
		if a > b {
			a, b = b, a
		}
		if a == 1 {
			r0[b-1] = true
		}
		if b == n {
			r1[nr1] = a - 1
			nr1++
		}
	}

	res := false
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true
		}
	}

	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

