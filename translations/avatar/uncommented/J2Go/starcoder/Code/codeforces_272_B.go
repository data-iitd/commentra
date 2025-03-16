package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		a[rec(x)]++
	}
	var answer float64
	for i := 0; i < 33; i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * (float64(a[i]) - 1)
		answer += summ
	}
	fmt.Println(int64(answer))
}

func rec(x int) int {
	var answer int
	for k := 31; k >= 0; k-- {
		if (x & (1 << uint(k)))!= 0 {
			answer++
		}
	}
	return answer
}

// 