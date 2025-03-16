
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	arr := make([]int, n)
	scanner.Scan()
	arr[0], _ = strconv.Atoi(scanner.Text())
	for i := 1; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		arr[i] = x + arr[i-1]
	}
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	q := make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		q[i], _ = strconv.Atoi(scanner.Text())
	}
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

func fun(arr []int, q int, n int, m int) int {
	res := 0
	i := 0
	j := n
	for i <= j {
		md := i + (j-i)/2
		if arr[md] == q {
			return md
		} else if arr[md] > q {
			res = md
			j = md - 1
		} else {
			i = md + 1
		}
	}
	return res
}

