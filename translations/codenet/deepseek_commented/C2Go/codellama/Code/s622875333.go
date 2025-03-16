package main

import "fmt"

func main() {
	var n, r, i, j, p, c int
	var a [100]int
	var b [100]int

	for {
		fmt.Scanf("%d %d", &n, &r)
		if n == 0 && r == 0 {
			break
		}

		for i = 0; i < n; i++ {
			a[i] = n - i
		}

		for i = 0; i < r; i++ {
			for j = 0; j < n; j++ {
				b[j] = a[j]
			}

			fmt.Scanf("%d %d", &p, &c)

			for j = 0; j < c; j++ {
				a[j] = b[p-1+j]
			}

			for j = c; j < c+p-1; j++ {
				a[j] = b[j-c]
			}
		}

		fmt.Println(a[0])
	}
}

