package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	d := 0
	for i := 0; i < n; i++ {
		for j := n - 1; j >= i+1; j-- {
			if a[j] < a[j-1] {
				temp := a[j]
				a[j] = a[j-1]
				a[j-1] = temp
				d++
			}
		}
	}

	fmt.Print(a[0])
	for i := 1; i < n; i++ {
		fmt.Printf(" %d", a[i])
	}
	fmt.Printf("\n%d\n", d)
}

// <END-OF-CODE>
