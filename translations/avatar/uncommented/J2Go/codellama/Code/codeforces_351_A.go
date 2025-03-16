
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	var arr = make([]float64, 2*n)
	var non_int int
	var sum_before float64
	var sum float64
	for i := 0; i < 2*n; i++ {
		var num float64
		fmt.Scan(&num)
		sum_before += num
		if num != float64(int(num)) {
			non_int++
		}
		sum += float64(int(num))
		arr[i] = num
	}
	var max_sum float64
	if non_int > n {
		max_sum = float64(non_int - n) + sum
	} else {
		max_sum = sum
	}
	var min_sum float64
	if non_int < n {
		min_sum = float64(n - non_int) + sum
	} else {
		min_sum = sum
	}
	var ans float64
	if min_sum > sum_before {
		ans = min_before - sum_before
	} else if max_sum < sum_before {
		ans = sum_before - max_sum
	} else {
		var x = sum_before - float64(int(sum_before))
		ans = math.Min(1-x, x)
	}
	fmt.Printf("%.3f", ans)
}

