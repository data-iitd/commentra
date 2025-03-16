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
	var sb strings.Builder

	// Reading the number of test cases
	n, _ := strconv.Atoi(readLine(reader))

	// Reading the elements of the array
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	arr := make([]float64, 2*n)
	nonInt := 0
	var sumBefore, sum float64

	// Iterating through the array elements and performing the required operations
	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64)
		sumBefore += num
		if num != math.Floor(num) {
			nonInt++
		}
		sum += math.Floor(num)
		arr[i] = num
	}

	// Calculating the maximum and minimum sums
	maxSum := math.Min(float64(n), float64(nonInt)) + sum
	minSum := math.Max(0, float64(nonInt)-float64(n)) + sum

	// Calculating the answer based on the given conditions
	var ans float64
	if minSum > sumBefore {
		ans = minSum - sumBefore
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum
	} else {
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x)
	}

	// Printing the answer
	fmt.Printf("%.3f\n", ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}
