package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the elements of the array")
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.ParseFloat(strings.TrimSpace(reader.ReadString('\n')), 64)
	}
	arr = sort.Float64Slice(arr)
	o := 2 * n - len(arr)
	arr_sum := 0.0
	for _, v := range arr {
		if v-float64(int(v))!= 0 {
			arr_sum += v
	}
	res := 2e9
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = min(res, math.Abs(float64(i)-arr_sum))
	}
	fmt.Printf("%.3f\n", res)
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

