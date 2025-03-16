<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	a := make([]int, N)
<<<<<<< HEAD
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &a[i])
	}
	ind_a := make([]int, N)
=======
	ind_a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &a[i])
	}
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i
	}
	used_inds := make(map[int]bool)
	ans := 0
	for i := 0; i < N; i++ {
		left_border := -1
		right_border := N
		cur_ind := ind_a[i]
		left_it := used_inds[cur_ind]
		right_it := used_inds[cur_ind+1]
		if left_it {
			left_border = cur_ind
		}
		if right_it {
			right_border = cur_ind + 1
		}
		ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)
		used_inds[cur_ind] = true
	}
	fmt.Println(ans)
}

