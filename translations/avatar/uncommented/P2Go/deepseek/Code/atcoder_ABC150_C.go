package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var orig []string
	for i := 1; i <= n; i++ {
		orig = append(orig, strconv.Itoa(i))
	}

	perms := permute(orig)

	var p, q string
	fmt.Scan(&p)
	fmt.Scan(&q)

	pn := findIndex(perms, p)
	qn := findIndex(perms, q)

	fmt.Println(math.Abs(float64(pn - qn)))
}

func permute(arr []string) []string {
	var result []string
	permuteHelper(arr, 0, len(arr)-1, &result)
	return result
}

func permuteHelper(arr []string, l int, r int, result *[]string) {
	if l == r {
		*result = append(*result, strings.Join(arr, ""))
	} else {
		for i := l; i <= r; i++ {
			arr[l], arr[i] = arr[i], arr[l]
			permuteHelper(arr, l+1, r, result)
			arr[l], arr[i] = arr[i], arr[l] // backtrack
		}
	}
}

func findIndex(arr []string, target string) int {
	for i, str := range arr {
		if str == target {
			return i
		}
	}
	return -1
}

