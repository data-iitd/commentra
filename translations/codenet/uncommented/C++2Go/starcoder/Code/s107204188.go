package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var minA int = math.MaxInt64
	var num int = 0
	var f int = 0
	var n, t int
	fmt.Scanf("%d %d", &n, &t)
	var A []int
	for i := 0; i < n; i++ {
		var a int
		fmt.Scanf("%d", &a)
		A = append(A, a)
		if minA > a {
			minA = a
		} else {
			if f == a-minA {
				num++
			} else if f < a-minA {
				num = 1
				f = a - minA
			}
		}
	}
	fmt.Println(num)
}

