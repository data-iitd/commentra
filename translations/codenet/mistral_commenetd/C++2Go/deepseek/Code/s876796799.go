package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	a := make([]int, N)
	ind_a := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i])
		ind_a[i] = i
	}

	used_inds := make(map[int]bool)
	var ans int64 = 0

	sort.Slice(ind_a, func(i, j int) bool {
		return a[ind_a[i]] < a[ind_a[j]]
	})

	for _, i := range ind_a {
		var left_border, right_border int

		cur_ind := i

		left_it := 0
		for left_it < len(used_inds) && list(used_inds)[left_it] <= cur_ind {
			left_it++
		}
		if left_it == 0 {
			left_border = -1
		} else {
			left_border = list(used_inds)[left_it-1]
		}

		right_it := 0
		for right_it < len(used_inds) && list(used_inds)[right_it] < cur_ind+1 {
			right_it++
		}
		if right_it == len(used_inds) {
			right_border = N
		} else {
			right_border = list(used_inds)[right_it]
		}

		ans += int64(cur_ind-left_border) * int64(right_border-cur_ind) * int64(i+1)

		used_inds[cur_ind] = true
	}

	fmt.Fprintln(writer, ans)
}

func list(m map[int]bool) []int {
	res := make([]int, 0, len(m))
	for k := range m {
		res = append(res, k)
	}
	return res
}
