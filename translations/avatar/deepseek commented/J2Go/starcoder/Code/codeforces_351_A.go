
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	var arr []float64
	var sum_before float64
	var sum float64
	var non_int int
	for i := 0; i < 2*n; i++ {
		var num float64
		fmt.Fscanln(reader, &num)
		sum_before += num
		if num!= float64(int(num)) {
			non_int++
		}
		sum += float64(int(num))
		arr = append(arr, num)
	}
	max_sum := float64(min(n, non_int)) + sum
	min_sum := float64(max(0, non_int-n)) + sum
	var ans float64
	if min_sum > sum_before {
		ans = min_sum - sum_before
	} else if max_sum < sum_before {
		ans = sum_before - max_sum
	} else {
		x := sum_before - float64(int(sum_before))
		ans = min(1-x, x)
	}
	fmt.Printf("%.3f", ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

