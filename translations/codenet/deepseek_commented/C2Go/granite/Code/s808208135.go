
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	N    = 100000
	INF  = 1000000
	SIZE = 500000
)

type Date struct {
	go, back, cost int
}

var (
	n, d [N]int
	a     [SIZE]Date
)

func main() {
	var (
		i, j, k, u, count int
	)
	data := bufio.NewScanner(os.Stdin)
	data.Scan()
	n, _ = strconv.Atoi(data.Text())
	for i = 0; i < n; i++ {
		data.Scan()
		u, _ = strconv.Atoi(data.Text())
		data.Scan()
		k, _ = strconv.Atoi(data.Text())
		for j = 0; j < k; j++ {
			data.Scan()
			a[count].back, _ = strconv.Atoi(data.Text())
			data.Scan()
			a[count].go, _ = strconv.Atoi(data.Text())
			data.Scan()
			a[count].cost, _ = strconv.Atoi(data.Text())
			count++
		}
	}
	root(count)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

func root(b int) {
	var (
		i, flag int
	)
	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0
	flag = 1
	for flag!= 0 {
		flag = 0
		for i = 0; i < b; i++ {
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = 1
			}
		}
	}
}

// 