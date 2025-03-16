package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N)

	a := make([]int64, N)
	ind_a := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i])
	}

	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i
	}

	used_inds := []int{}
	ans := int64(0)

	for i := 0; i < N; i++ {
		cur_ind := ind_a[i]
		left_border := -1
		right_border := N

		// Find left border
		left_it := sort.Search(len(used_inds), func(j int) bool {
			return used_inds[j] >= cur_ind
		})

		if left_it > 0 {
			left_border = used_inds[left_it-1]
		}

		// Find right border
		right_it := sort.Search(len(used_inds), func(j int) bool {
			return used_inds[j] > cur_ind
		})

		if right_it < len(used_inds) {
			right_border = used_inds[right_it]
		}

		ans += (int64(cur_ind-left_border) * int64(right_border-cur_ind) * int64(i+1))

		// Insert current index into used indices
		used_inds = append(used_inds, cur_ind)
		sort.Ints(used_inds) // Keep used_inds sorted
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
