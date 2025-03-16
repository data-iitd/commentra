
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func getNums(num, t int) []int {
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
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)
	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)
	fmt.Println(strings.Join(func() []string {
		ansStr := make([]string, len(ans))
		for i, v := range ans {
			ansStr[i] = strconv.Itoa(v)
		}
		return ansStr
	}(), " "))
}

