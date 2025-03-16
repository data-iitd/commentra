package main

import (
	"fmt"
	"math"
)

func calculate(n int, s string) {
	arr := []byte(s)
	rNum := 0
	gNum := 0
	bNum := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] == 'R' {
			rNum++
		} else if arr[i] == 'G' {
			gNum++
		} else if arr[i] == 'B' {
			bNum++
		}
	}
	sum := 0
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		for i := 0; i < n-2*step; i++ {
			s := string(arr[i]) + string(arr[i+step]) + string(arr[i+step*2])
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	calculate(n, s)
}

