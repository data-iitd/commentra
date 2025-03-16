package main

import "fmt"

func getNums(num, t int) []int {
	var ans []int
	for i := 0; i < num; i++ {
		if i < t%num {
			ans = append(ans, t/num+1)
		} else {
			ans = append(ans, t/num)
		}
	}
	return ans
}

func main() {
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)
	ans := getNums(k, sk)
	ans = append(ans, getNums(n-k, sa-sk)...)
	fmt.Println(ans)
}

