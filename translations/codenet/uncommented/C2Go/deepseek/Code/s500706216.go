package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	tmpa := make([]int, n)
	light := make([]int, n+2)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		if r < 0 {
			r = 0
		}
		light[r]++
		if l+1 > n {
			l = n + 1
		}
		light[l+1]--
	}

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
			if r < 0 {
				r = 0
			}
			light[r]--
			if l+1 > n {
				l = n + 1
			}
			light[l+1]++
			r = j - a[j]
			l = j + a[j]
			if r < 0 {
				r = 0
			}
			light[r]++
			if l+1 > n {
				l = n + 1
			}
			light[l+1]--
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
	}
	for j := 0; j < n; j++ {
		fmt.Print(a[j])
		if j != n-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}
