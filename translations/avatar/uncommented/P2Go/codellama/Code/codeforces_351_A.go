
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	arr = arr[1:]
	sort.Float64s(arr)
	o := 2*n - len(arr)
	arr_sum := 0.0
	for _, v := range arr {
		arr_sum += v
	}
	res := math.MaxInt64
	for i := 0; i < n+1; i++ {
		if i+o >= n {
			res = int(math.Min(float64(res), math.Abs(float64(i)-arr_sum)))
		}
	}
	fmt.Println(res)
}

