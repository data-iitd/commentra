package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of rows: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of columns: ")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of x: ")
	x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Println("Enter the value of a[", i, "][", j, "]: ")
			a[i][j], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		}
	}
	min := int(^uint(0) >> 1)
	for i := 0; i < int(math.Pow(2, float64(n))); i++ {
		status := make([]int, n)
		for j := 0; j < n; j++ {
			if (1 & i >> j) == 1 {
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
			min = int(math.Min(float64(min), float64(res[0])))
		}
	}
	if min == int(^uint(0) >> 1) {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}

