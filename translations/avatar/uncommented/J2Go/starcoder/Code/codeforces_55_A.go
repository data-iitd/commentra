package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, i, k, p int
	var flag bool
	a := make([]int, 1000)
	scan := bufio.NewScanner(os.Stdin)
	n, _ = strconv.Atoi(scan.Text())
	i = 1
	k = 0
	p = 1
	flag = true
	for k <= n {
		i += k
		if i >= n {
			for!(i < n) {
				i = i - n
			}
		}
		a[i]++
		k++
	}
	for i = 0; i < n; i++ {
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

