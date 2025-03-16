package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	s := ""
	for n > 0 {
		x := n % 2
		n /= 2
		s = fmt.Sprintf("%s%d", s, x)
	}
	ans := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			ans++
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
