package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(reader, &n)
	st := bufio.NewScanner(reader)
	st.Scan()
	tokens := strings.Split(st.Text(), " ")
	arr := make([]float64, 2*n)
	non_int := 0
	sum_before := 0.0
	sum := 0.0
	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64)
		sum_before += num
		if num != math.Floor(num) {
			non_int++
		}
		sum += math.Floor(num)
		arr[i] = num
	}
	max_sum := math.Min(float64(n), float64(non_int)) + sum
	min_sum := math.Max(0, float64(non_int-n)) + sum
	var ans float64
	if min_sum > sum_before {
		ans = min_sum - sum_before
	} else if max_sum < sum_before {
		ans = sum_before - max_sum
	} else {
		x := sum_before - math.Floor(sum_before)
		ans = math.Min(1-x, x)
	}
	fmt.Printf("%.3f\n", ans)
}

