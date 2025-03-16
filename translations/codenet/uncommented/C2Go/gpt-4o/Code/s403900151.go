package main

import (
	"fmt"
)

func main() {
	var n, r, p, c int

	for {
		_, err := fmt.Scanf("%d %d", &n, &r)
		if err != nil || (n == 0 && r == 0) {
			break
		}

		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}

		for i := 0; i < r; i++ {
			fmt.Scanf("%d %d", &p, &c)

			b := make([]int, c)
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}
			for j := 0; j < p-1; j++ {
				a[n-p-c+1+j] = a[n-p+j+1]
			}
			for j, k := n-p-c+1+j, 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}
		}
		fmt.Println(a[n-1])
	}
}

// <END-OF-CODE>
