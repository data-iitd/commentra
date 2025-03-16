
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	c := make(map[int]bool)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		c[s.Index("S")-s.Index("G")] = true
	}
	if len(c) == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}

