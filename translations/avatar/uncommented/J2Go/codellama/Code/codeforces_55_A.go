
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, i, k, p int
	var flag bool
	var a [1000]int
	var s string
	var err error

	s, err = os.ReadFile("input.txt")
	if err != nil {
		fmt.Println(err)
		return
	}

	n, err = strconv.Atoi(s)
	if err != nil {
		fmt.Println(err)
		return
	}

	i = 0
	k = 1
	p = 1
	flag = true

	for k <= n {
		i += k
		if i >= n {
			for !(i < n) {
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

