package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, i, cnt int
	flag := make([]int, 50001)

	for i = 2; i*i <= 50000; i++ {
		if flag[i] == 0 {
			for j := i * 2; j <= 50000; j += i {
				flag[j] = 1
			}
		}
	}

	for {
		fmt.Fscanf(os.Stdin, "%d", &n)
		if n == 0 {
			break
		}
		i = 2
		cnt = 0
		for ; i*2 <= n; i++ {
			if flag[i] == 0 && flag[n-i] == 0 {
				cnt++
			}
		}
		fmt.Println(cnt)
	}
}

