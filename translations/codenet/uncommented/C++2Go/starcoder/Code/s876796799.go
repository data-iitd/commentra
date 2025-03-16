package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &a[i])
	}
	ind_a := make([]int, N)
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i
	}
	used_inds := make(map[int]bool)
	ans := 0
	for i := 0; i < N; i++ {
		cur_ind := ind_a[i]
		left_border := -1
		right_border := N
		if left_border == -1 {
			left_border = -1
		} else {
			if _, ok := used_inds[cur_ind];!ok {
				left_border = -1
			} else {
				left_border = -1
			}
		}
		if right_border == N {
			right_border = N
		} else {
			if _, ok := used_inds[cur_ind+1];!ok {
				right_border = N
			} else {
				right_border = cur_ind + 1
			}
		}
		ans += (cur_ind - left_border) * (right_border - cur_ind) * ((int)(i) + 1)
		used_inds[cur_ind] = true
	}
	fmt.Printf("%d\n", ans)
}

