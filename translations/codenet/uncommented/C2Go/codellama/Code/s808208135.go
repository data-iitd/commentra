package main

import "fmt"

const (
	N = 100000
	INF = 1000000
)

type Date struct {
	go, back, cost int
}

var n int
var d [N]int
var a [500000]Date

func root(b int) {
	var i, flag int

	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0

	for flag != 0 {
		flag = 0
		for i = 0; i < b; i++ {
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = 1
			}
		}
	}
}

func main() {
	var i, j, k, u, count int
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)
		for j = 0; j < k; j++ {
			a[count].back = u
			fmt.Scan(&a[count].go, &a[count].cost)
			count++
		}
	}
	root(count)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

