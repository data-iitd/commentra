
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	m, _ := strconv.Atoi(read(reader))
	x, _ := strconv.Atoi(read(reader))
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			a[i][j], _ = strconv.Atoi(read(reader))
		}
	}
	min := 1000000001
	for i := 0; i < 1<<n; i++ {
		status := make([]int, n)
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
				status[j] = 1
			}
		}
		res := make([]int, m+1)
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}
		if flag {
			if res[0] < min {
				min = res[0]
			}
		}
	}
	if min == 1000000001 {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(str)
}

