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
	fmt.Fscan(reader, &n)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(readInt(reader))]++
	}
	var answer float64
	for i := 0; i < 33; i++ {
		summ := (1 + a[i] - 1) / 2.0 * (a[i] - 1)
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

func readInt(reader *bufio.Reader) int {
	str, _, _ := reader.ReadLine()
	i, _ := strconv.Atoi(strings.TrimSpace(string(str)))
	return i
}

