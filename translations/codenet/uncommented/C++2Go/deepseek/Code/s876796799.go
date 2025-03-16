package main

import (
	"bufio"
	"fmt"
	"os"
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

	used_inds := make(map[int]bool)
	var ans int64 = 0
	for i := 0; i < N; i++ {
		var left_border, right_border int
		cur_ind := ind_a[i]
		left_it := cur_ind
		right_it := cur_ind + 1

		for {
			if val, exists := used_inds[left_it]; exists && val {
				left_it--
			} else {
				break
			}
		}
		for {
			if val, exists := used_inds[right_it]; exists && val {
				right_it++
			} else {
				break
			}
		}

		if left_it == -1 {
			left_border = -1
		} else {
			left_border = left_it
		}
		if right_it == N {
			right_border = N
		} else {
			right_border = right_it
		}
		ans += int64(cur_ind-left_border) * int64(right_border-cur_ind) * int64(i+1)

		used_inds[cur_ind] = true
	}

	fmt.Println(ans)
}

