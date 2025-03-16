package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n := toInt(scanner.Text())
	arr := make([]int, n)
	scanner.Scan()
	arr[0] = toInt(scanner.Text())
	for i := 1; i < n; i++ {
		scanner.Scan()
		x := toInt(scanner.Text())
		arr[i] = x + arr[i-1]
	}
	scanner.Scan()
	m := toInt(scanner.Text())
	q := make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		q[i] = toInt(scanner.Text())
	}
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func fun(arr []int, q int, n int, m int) int {
	res := 0
	i, j := 0, n
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

