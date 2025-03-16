package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	ind_a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i
	}

	used_inds := make([]int, 0)
	ans := 0
	for i := 0; i < N; i++ {
		cur_ind := ind_a[i]
		left_border := sort.SearchInts(used_inds, cur_ind)
		if left_border == len(used_inds) {
			left_border = -1
		} else if used_inds[left_border] > cur_ind {
			left_border--
		}
		right_border := sort.SearchInts(used_inds, cur_ind+1)
		if right_border == len(used_inds) {
			right_border = N
		} else {
			right_border = used_inds[right_border]
		}
		ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)
		used_inds = append(used_inds, cur_ind)
	}

	fmt.Println(ans)
}

