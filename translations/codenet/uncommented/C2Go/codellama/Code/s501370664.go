package main

import "fmt"

var flag []int

func prime(num int) {
	var i, j int

	flag = make([]int, num+1)

	for i = 2; i*i <= num; i++ {
		if flag[i] == 0 {
			for j = 2; i*j <= num; j++ {
				flag[i*j] = 1
			}
		}
	}
}

func main() {
	var n, i, cnt int

	prime(50000)

	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		i = 2
		cnt = 0
		for i*2 <= n {
			if flag[i] == 0 && flag[n-i] == 0 {
				cnt++
			}
			i++
		}
		fmt.Println(cnt)
	}
}

