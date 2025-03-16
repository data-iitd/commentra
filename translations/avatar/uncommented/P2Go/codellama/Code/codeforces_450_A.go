
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	l2 := make([]int, n)
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}
	mx := 0
	for i := 0; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
		}
	}
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			fmt.Println(i + 1)
		}
	}
}

