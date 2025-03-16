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
		switch char {
		case "R":
			rNum++
		case "G":
			gNum++
		case "B":
			bNum++
		}
	}

	sum := 0
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		for i := 0; i <= n-2*step; i++ {
			subStr := arr[i] + arr[i+step] + arr[i+2*step]
			if subStr == "RGB" || subStr == "RBG" || subStr == "BGR" || subStr == "BRG" || subStr == "GBR" || subStr == "GRB" {
				sum++
			}
		}
	}

	fmt.Println(rNum*gNum*bNum - sum)
}

func main() {
	var N int
	fmt.Scan(&N)
	var S string
	fmt.Scan(&S)
	calculate(N, S)
}

// <END-OF-CODE>
