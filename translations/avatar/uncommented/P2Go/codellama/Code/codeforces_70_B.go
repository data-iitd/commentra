package main

import (
	"fmt"
	"regexp"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans, sumL := 1, 0
	for _, s := range regexp.MustCompile("[.?!]").Split(input(), -1) {
		s = s + "."
		L := len(s)
		if L > 1 {
			if L > n {
				fmt.Println("Impossible")
				return
			}
			if sumL+L+(sumL > 0) > n {
				ans++
				sumL = L
			} else {
				sumL = sumL + L + (sumL > 0)
			}
		}
	}
	fmt.Println(ans)
}

// 