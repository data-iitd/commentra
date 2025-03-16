package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	q := make([][]string, n)
	count := 0

	for i := 0; i < n; i++ {
		var a string
		fmt.Scan(&a)
		q[i] = append(q[i], a)
	}

	for _, j := range q {
		for _, k := range q {
			if k == j {
				continue
			} else if j[0] == k[len(k)-1][0] {
				count++
			}
		}
	}
	fmt.Println(count)
}

// <END-OF-CODE>
