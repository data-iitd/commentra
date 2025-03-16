package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Fscan(reader, &n, &k)
	logs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &logs[i])
	}
	min, max := 1, 1e9+1000
	for min < max {
		mid := (min + max) / 2
		if nei(mid, logs, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Println(min)
}

func nei(mid int, logs []int, k int) bool {
	for _, log := range logs {
		k -= (log + mid - 1) / mid - 1
		if k < 0 {
			return false
		}
	}
	return true
}

// 