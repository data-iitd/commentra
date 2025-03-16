
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, i, k, p int
	var flag bool
	var a [1000]int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	i = 0
	for k = 1; k <= n; k++ {
		i += k
		if i >= n {
			for i < n {
				i = i - n
			}
		}
		a[i]++
	}
	flag = true
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

