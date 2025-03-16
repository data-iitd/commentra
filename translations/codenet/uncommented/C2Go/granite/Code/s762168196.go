
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		sum += a[i]
	}
	max, min := a[0], a[0]
	for i := 1; i < n; i++ {
		if a[i] > max {
			max = a[i]
		}
		if a[i] < min {
			min = a[i]
		}
	}
	fmt.Printf("%d %d %d\n", min, max, sum)
}

