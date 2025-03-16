
package main

import "fmt"

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	curr := r
	s := 0
	for curr > 0 {
		s++
		curr /= 10
	}
	first := 10 ** s
	second := first / 2
	ans := -1
	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr = i
			rev := ""
			for _, k := range fmt.Sprintf("%d", curr) {
				rev += fmt.Sprintf("%d", 9-int(k))
			}
			ans = max(ans, int(rev)*curr)
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

