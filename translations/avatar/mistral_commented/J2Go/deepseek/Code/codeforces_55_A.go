package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, i, k, p int
	var flag bool
	var a [1000]int

	scanner.Scan()
	n = atoi(scanner.Text())

	i = 1
	k = 0
	p = 1
	flag = true

	for k <= n {
		i += k
		if i >= n {
			for i >= n {
				i -= n
			}
		}
		a[i]++
		k++
	}

	for i := 0; i < n; i++ {
		if a[i] == 0 {
			flag = false
			break
		}
	}

	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func atoi(s string) int {
	sign, n := 1, 0
	for _, v := range s {
		if v == '-' {
			sign = -1
		} else {
			n = n*10 + int(v-'0')
		}
	}
	return sign * n
}

