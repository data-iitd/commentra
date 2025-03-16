
package main

import "fmt"

func main() {
	var n, i, j, q, sum int
	var x [10000]int
	var y [500]int

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &x[i])
	}

	fmt.Scanf("%d", &q)

	for i = 0; i < q; i++ {
		fmt.Scanf("%d", &y[i])
	}

	for i = 0; i < q; i++ {
		for j = 0; j < n; j++ {
			if y[i] == x[j] {
				sum = sum + 1
				break
			}
		}
	}

	fmt.Printf("%d\n", sum)
}

