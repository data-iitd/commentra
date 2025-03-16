
package main

import "fmt"

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	lista := make([]int, n)
	listb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lista[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&listb[i])
	}
	for i := 0; i < n; i++ {
		if lista[i] == a {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

