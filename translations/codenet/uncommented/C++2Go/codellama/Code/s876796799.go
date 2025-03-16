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
		left_border := -1
		right_border := N
		cur_ind := ind_a[i]
		sort.Ints(used_inds)
		for j := 0; j < len(used_inds); j++ {
			if used_inds[j] > cur_ind {
				left_border = used_inds[j]
				break
			}
		}
		for j := len(used_inds) - 1; j >= 0; j-- {
			if used_inds[j] < cur_ind {
				right_border = used_inds[j]
				break
			}
		}
		ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

		//fmt.Println(i, left_border, right_border)
		//fmt.Println(ans)

		used_inds = append(used_inds, cur_ind)
	}

	fmt.Println(ans)
}

