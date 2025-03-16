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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	logsLength := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &logsLength[i])
	}

	min, max := 1, int(1e9)+1000
	for min < max {
		mid := (min + max) / 2
		if nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Fprintln(writer, min)
}

func nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}
