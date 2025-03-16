package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var arr []float64
	input, _ := fmt.Scanln()
	parts := strings.Split(input, " ")
	for _, part := range parts {
		num, _ := strconv.ParseFloat(part, 64)
		arr = append(arr, num)
	}

	var filteredArr []float64
	for _, num := range arr {
		if num != float64(int(num)) {
			filteredArr = append(filteredArr, num-float64(int(num)))
		}
	}

	sort.Float64s(filteredArr)

	o := 2*n - len(filteredArr)
	arrSum := 0.0
	for _, num := range filteredArr {
		arrSum += num
	}

	res := int(2e9)
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = min(res, abs(float64(i)-arrSum))
		}
	}

	fmt.Printf("%.3f\n", float64(res))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}
