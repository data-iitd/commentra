package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func main() {
	var n int
	fmt.Scan(&n)

	cnt := make([]int, 26)
	for i := range cnt {
		cnt[i] = 1
	}

	s := make([]rune, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
		cnt[s[i]-'a']++
	}

	ans := int64(cnt[0])
	for i := 1; i < 26; i++ {
		ans *= int64(cnt[i])
		ans %= int64(MOD)
	}

	fmt.Println(ans - 1)
}

// <END-OF-CODE>
