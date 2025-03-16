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
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	arr := make([]float64, 2*n)
	nonInt := 0
	sumBefore := 0.0
	sum := 0.0

	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64)
		sumBefore += num
		if num != math.Floor(num) {
			nonInt++
		}
		sum += math.Floor(num)
		arr[i] = num
	}

	maxSum := math.Min(float64(n), float64(nonInt)) + sum
	minSum := math.Max(0, float64(nonInt-n)) + sum
	var ans float64

	if minSum > sumBefore {
		ans = minSum - sumBefore
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum
	} else {
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x)
	}

	fmt.Printf("%.3f\n", ans)
}

// <END-OF-CODE>
