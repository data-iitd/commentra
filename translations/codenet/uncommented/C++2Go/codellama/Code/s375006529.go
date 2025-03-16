package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	n := len(s)
	v := make([]int, 26)
	for i := 0; i < n; i++ {
		v[s[i]-'a']++
	}
	ans := "Yes"
	for i := 0; i < 26; i++ {
		if v[i]%2 != 0 {
			ans = "No"
			break
		}
	}
	fmt.Println(ans)
}

