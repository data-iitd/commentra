
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func get_nums(num, t int) []int {
	ans := make([]int, num)
	for i := 0; i < num; i++ {
		if i < t%num {
			ans[i] = t/num + 1
		} else {
			ans[i] = t/num
		}
	}
	return ans
}

func main() {
	n, k, l, r, sa, sk := 0, 0, 0, 0, 0, 0
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk)
	ans := make([]int, n)
	for i := 0; i < k; i++ {
		ans[i] = sk + 1
	}
	for i := k; i < n; i++ {
		ans[i] = sa - sk
	}
	fmt.Println(strings.Join(strings.Fields(fmt.Sprint(ans)), " "))
}

