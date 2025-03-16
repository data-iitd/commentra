
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	var c int
	for i := 0; i < 2; i++ {
		c += max(a, b)
		if a >= b {
			a--
		} else {
			b--
		}
	}
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

