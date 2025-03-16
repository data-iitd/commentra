package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	ch := make([]rune, n)
	s1, s2 := 0, 0
	j := 0
	flag := 0

	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		temp1 := s1 + x
		temp2 := s2 + y

		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x
			ch[j] = 'A'
			j++
			continue
		}
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y
			ch[j] = 'G'
			j++
			continue
		}
		flag = 1
		break
	}

	if flag == 1 {
		fmt.Println(-1)
	} else {
		ans := string(ch[:j])
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
