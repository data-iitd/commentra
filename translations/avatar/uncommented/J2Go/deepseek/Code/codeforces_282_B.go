package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	ch := make([]byte, n)
	var s1, s2 int
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		temp1 := s1 + x
		temp2 := s2 + y
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x
			ch[i] = 'A'
		} else if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y
			ch[i] = 'G'
		} else {
			fmt.Println(-1)
			return
		}
	}
	ans := string(ch)
	fmt.Println(ans)
}

