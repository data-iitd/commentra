package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var a, b []int
	var temp, q, w, e int
	var f bool
	fmt.Scanf("%d", &n)
	a = make([]int, n)
	b = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
		fmt.Scanf("%d", &b[i])
		if temp < a[i] {
			if q > b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if temp > a[i] {
			if q < b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if a[i] > w {
			w = a[i]
			if b[i] < e {
				f = true
			}
			e = b[i]
		}
		if a[i] < w {
			if b[i] > e {
				f = true
			}
		}
	}
	if f == true {
		fmt.Println("Happy Alex")
	} else {
		fmt.Println("Poor Alex")
	}
}

