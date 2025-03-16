package main

import (
	"fmt"
	"math"
)

const N = 100000
const INF = 1000000

type Date struct {
	go   int
	back int
	cost int
}

var n int
var d [N]int
var a [500000]Date

func root(b int) {
	for i := 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0

	flag := true
	for flag {
		flag = false
		for i := 0; i < b; i++ {
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = true
			}
		}
	}
}

func main() {
	var count int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var u, k int
		fmt.Scan(&u, &k)
		for j := 0; j < k; j++ {
			a[count].back = u
			fmt.Scan(&a[count].go, &a[count].cost)
			count++
		}
	}
	root(count)
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

// <END-OF-CODE>
