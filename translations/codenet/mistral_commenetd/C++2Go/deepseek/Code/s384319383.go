package main

import (
	"fmt"
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

	ans := int64(1)
	for i := 0; i < 26; i++ {
		ans *= int64(cnt[i])
	}

	ans--
	fmt.Println(ans)
}

