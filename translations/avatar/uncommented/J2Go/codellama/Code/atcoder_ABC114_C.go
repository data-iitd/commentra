
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	i := 357
	c := 0
	for i <= N {
		s := strconv.Itoa(i)
		if s[0] == '3' && s[1] == '5' && s[2] == '7' {
			c++
		}
		sb := ""
		f := false
		for j := 0; j < len(s); j++ {
			a := s[len(s)-1-j]
			if f {
				sb += string(a)
			} else {
				if a == '3' {
					sb += "5"
					f = true
				} else if a == '5' {
					sb += "7"
					f = true
				} else {
					sb += "3"
				}
			}
		}
		if !f {
			sb += "3"
		}
		sb2 := ""
		for j := len(sb) - 1; j >= 0; j-- {
			sb2 += string(sb[j])
		}
		i, _ = strconv.ParseInt(sb2, 10, 64)
	}
	fmt.Println(c)
}

