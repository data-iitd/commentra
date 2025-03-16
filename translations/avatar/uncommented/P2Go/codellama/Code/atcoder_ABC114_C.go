package main

import "fmt"

func main() {
	N := 1000000
	aaa := func(n int) int {
		if n > N {
			return 0
		}
		ans := 1
		if set(n) == []int{7, 5, 3} {
			ans = 1
		} else {
			ans = 0
		}
		for _, i := range []int{7, 5, 3} {
			ans += aaa(n + i)
		}
		return ans
	}
	fmt.Println(aaa(0))
}

func set(n int) []int {
	s := []int{}
	for n > 0 {
		s = append(s, n%10)
		n /= 10
	}
	return s
}

