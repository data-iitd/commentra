
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n, i, k, p int
		flag       bool
		a          [1000]int
	)

	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)

	n, _ = strconv.Atoi(scan.Text())

	i = 1
	k = 0
	p = 1
	flag = true

	for k <= n {
		i += k
		if i >= n {
			for i >= n {
				i = i - n
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

