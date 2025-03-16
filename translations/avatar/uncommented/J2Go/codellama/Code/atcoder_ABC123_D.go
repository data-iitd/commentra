package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var x [3]int
	var max int
	for i := 0; i < 3; i++ {
		fmt.Scan(&x[i])
		if x[i] > max {
			max = x[i]
		}
	}
	var k int
	fmt.Scan(&k)
	a := make([][]int, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int, x[i])
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < x[i]; j++ {
			fmt.Scan(&a[i][j])
		}
		sort.Ints(a[i])
	}
	ans := make([]int, 0)
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}
	sort.Ints(ans)
	n := len(ans)
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

