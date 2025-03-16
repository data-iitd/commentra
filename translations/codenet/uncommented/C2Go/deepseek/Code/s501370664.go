package main

import (
	"fmt"
	"runtime"
)

var flag []bool

func prime(num int) {
	i, j := 2, 2

	flag = make([]bool, num+1)

	for i*i <= num {
		if !flag[i] {
			for j = 2; i*j <= num; j++ {
				flag[i*j] = true
			}
		}
		i++
	}
}

func main() {
	var n, i, cnt int

	prime(50000)

	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		i = 2
		cnt = 0
		for i*2 <= n {
			if !flag[i] && !flag[n-i] {
				cnt++
			}
			i++
		}
		fmt.Println(cnt)
	}
}

