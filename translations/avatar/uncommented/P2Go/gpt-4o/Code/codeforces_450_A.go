package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	l2 := make([]int, n)
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}

	mx := math.MinInt64
	for _, value := range l2 {
		if value > mx {
			mx = value
		}
	}

	var ind int
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			ind = i
			break
		}
	}

	fmt.Println(ind + 1)
}

// <END-OF-CODE>
