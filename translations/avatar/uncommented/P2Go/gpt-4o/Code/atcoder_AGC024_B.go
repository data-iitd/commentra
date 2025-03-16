package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
	}
	editorial(N, P)
}

func editorial(N int, P []int) {
	if N == 1 {
		fmt.Println(0)
		return
	}
	a := make([]int, N+1)
	for i, p := range P {
		a[p] = i
	}
	tmp := 1
	maxLen := 1
	for i := 1; i < N; i++ {
		if a[i] < a[i+1] {
			tmp++
			if tmp > maxLen {
				maxLen = tmp
			}
		} else {
			tmp = 1
		}
	}
	ans := N - maxLen
	fmt.Println(ans)
}

func WA(N int, P []int) {
	tmp := 0
	ans := 0
	for i, p := range P {
		if i == 0 || P[i-1]+1 == p {
			tmp++
		} else {
			if ans < tmp {
				ans = tmp
			}
			tmp = 1
		}
	}
	if ans < tmp {
		ans = tmp
	}
	fmt.Println(N - ans)
}

// <END-OF-CODE>
