
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	q := n / m
	r := n % m
	a := make([]int, m)
	for i := 0; i < m; i++ {
		a[i] = q
	}
	for i := 0; i < r; i++ {
		a[i]++
	}
	for i := 0; i < m; i++ {
		fmt.Print(a[i], " ")
	}
}