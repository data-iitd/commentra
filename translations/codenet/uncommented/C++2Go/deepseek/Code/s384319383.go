package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	cnt := make([]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = 1
	}

	s := make([]rune, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
		cnt[s[i]-'a']++
	}

	ans := float64(cnt[0])
	for i := 1; i < 26; i++ {
		ans *= float64(cnt[i])
		ans = math.Mod(ans, 1e9+7)
	}

	fmt.Println(int(ans) - 1)
}

