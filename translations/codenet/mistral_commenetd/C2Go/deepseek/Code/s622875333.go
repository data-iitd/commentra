package main

import (
	"fmt"
)

func main() {
	var n, r, i, j, p, c int
	var a, b []int

	for {
		fmt.Print("Enter the number of elements in array a: ")
		fmt.Scan(&n)
		fmt.Print("Enter the number of rotations: ")
		fmt.Scan(&r)

		if n == 0 && r == 0 {
			break
		}

		a = make([]int, n)
		for i = 0; i < n; i++ {
			a[i] = n - i
		}

		for i = 0; i < r; i++ {
			fmt.Printf("\nBefore rotation %d:\n", i+1)
			for j = 0; j < n; j++ {
				fmt.Printf("%d ", a[j])
			}
			fmt.Println()

			b = make([]int, n)
			copy(b, a)

			fmt.Print("Enter the number of elements to be rotated: ")
			fmt.Scan(&c)
			fmt.Print("Enter the position: ")
			fmt.Scan(&p)

			for j = 0; j < c; j++ {
				b[j] = b[j+1]
			}

			for j = 0; j < c; j++ {
				a[j] = b[p-1+j]
			}

			for j = c; j < n; j++ {
				a[j] = b[j-c]
			}

			fmt.Printf("\nAfter rotation %d:\n", i+1)
			for j = 0; j < n; j++ {
				fmt.Printf("%d ", a[j])
			}
			fmt.Println()
		}

		fmt.Printf("\nThe first element of the final array is: %d\n", a[0])
	}
}

