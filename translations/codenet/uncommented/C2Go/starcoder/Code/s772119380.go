package main

import "fmt"

func main() {
	var a [1000]int
	var n, i, j, d int
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i = 0; i < n; i++ {
		for j = n - 1; j >= i+1; j-- {
			if a[j] < a[j-1] {
				a[j], a[j-1] = a[j-1], a[j]
				d++
			}
		}
	}
	fmt.Printf("%d", a[0])
	for i = 1; i < n; i++ {
		fmt.Printf(" %d", a[i])
	}
	fmt.Printf("\n%d\n", d)
}

