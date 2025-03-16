
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	arr := readLine(reader)
	arr = strings.Split(arr, " ")
	var fractionalParts []float64
	for _, v := range arr {
		if v!= "0" {
			fractionalParts = append(fractionalParts, float64(strings.TrimSuffix(v, ".0")))
		}
	}
	sort.Float64s(fractionalParts)
	o := 2*n - len(fractionalParts)
	var arrSum float64
	for _, v := range fractionalParts {
		arrSum += v
	}
	res := int(2e9)
	for i := 0; i <= n; i++ {
		if i+o >= n {
			if int(arrSum+0.5) == i {
				res = 0
				break
			}
			if int(arrSum+0.5) > i {
				res = int(min(float64(res), math.Abs(float64(i-int(arrSum+0.5)))))
			} else {
				res = int(min(float64(res), math.Abs(float64(i-int(arrSum+0.5)))))
			}
		}
	}
	fmt.Printf("%.3f", res)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

func min(x, y float64) float64 {
	if x < y {
		return x
	}
	return y
}

