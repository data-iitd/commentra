package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	tmpa := make([]int, n)
	light := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		light[(r < 0 ? 0 : r)]++
		light[(l + 1 > n ? n + 1 : l + 1)]--
	}
	// for i := 0; i <= n; i++ {
	// 	fmt.Printf("%d ", light[i])
	// }
	// fmt.Println()
	for i := 0; i < k; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}
		for j := 0; j < n; j++ {
			r := j - tmpa[j]
			l := j + tmpa[j]
			light[(r < 0 ? 0 : r)]--
			light[(l + 1 > n ? n + 1 : l + 1)]++
			r = j - a[j]
			l = j + a[j]
			light[(r < 0 ? 0 : r)]++
			light[(l + 1 > n ? n + 1 : l + 1)]--
		}
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
		// for j := 0; j < n; j++ {
		// 	fmt.Printf("%d", a[j])
		// 	fmt.Print(j == n-1 ? "\n" : " ")
		// }
	}
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		fmt.Print(j == n-1 ? "\n" : " ")
	}
}

