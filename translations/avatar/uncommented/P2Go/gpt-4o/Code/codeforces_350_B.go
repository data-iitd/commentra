package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	t := make([]int, n+1)
	t[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&t[i])
	}

	a := make([]int, n+1)
	a[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	ans := []int{}
	cnt := make([]int, n+1)

	for _, value := range a {
		cnt[value]++
	}

	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := []int{i}
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = make([]int, len(crt))
				copy(ans, crt)
			}
		}
	}

	// Reverse the answer slice
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	fmt.Println(len(ans))
	fmt.Println(strings.Join(intSliceToStringSlice(ans), " "))
}

func intSliceToStringSlice(slice []int) []string {
	strSlice := make([]string, len(slice))
	for i, v := range slice {
		strSlice[i] = fmt.Sprintf("%d", v)
	}
	return strSlice
}
