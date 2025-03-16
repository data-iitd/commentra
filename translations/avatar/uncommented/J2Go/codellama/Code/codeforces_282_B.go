package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n int
	var s1, s2 int
	var ch []string
	var i, j int
	var flag int
	var dif int
	var temp1, temp2 int

	fmt.Scan(&n)
	ch = make([]string, n)
	s1 = 0
	s2 = 0
	for i = 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x)
		fmt.Scan(&y)
		temp1 = s1 + x
		temp2 = s2 + y
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x
			ch[j] = "A"
			j++
			continue
		}
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y
			ch[j] = "G"
			j++
			continue
		}
		flag = 1
		break
	}
	if flag == 1 {
		fmt.Println(-1)
	} else {
		var ans string
		ans = strconv.Itoa(ch)
		fmt.Println(ans)
	}
}

