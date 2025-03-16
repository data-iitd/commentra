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
	for i := range r0 {
		r0[i] = false
	}
	r1 := make([]int, n)
	nr1 := 0
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < m; i++ {
		scanner.Scan()
		var a, b int
		fmt.Sscanf(scanner.Text(), "%d%d", &a, &b)
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
			break
		}
	}
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

