package main

import (
	"fmt"
	"math"
	"strings"
)

func calculate(n int, s string) {
	arr := strings.Split(s, "")
	rNum := 0
	gNum := 0
	bNum := 0
	for _, char := range arr {
		if char == "R" {
			rNum++
		} else if char == "G" {
			gNum++
		} else if char == "B" {
			bNum++
		}
	}
	sum := 0
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		for i := 0; i <= n-2*step; i++ {
			s := arr[i] + arr[i+step] + arr[i+step*2]
			if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
				sum++
			}
		}
	}
	fmt.Println(rNum * gNum * bNum - sum)
}

func main() {
	var N int
	var S string
	fmt.Scan(&N)
	fmt.Scan(&S)
	calculate(N, S)
}

