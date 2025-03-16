package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}
	result := 0
	for b := 0; b < 60; b++ {
		bs := 0
		for i := 0; i < N; i++ {
			if A[i]&(1<<b) != 0 {
				bs++
			}
		}
		result = (result + bs*(N-bs)*(1<<b))%1000000007
	}
	fmt.Println(result)
}

