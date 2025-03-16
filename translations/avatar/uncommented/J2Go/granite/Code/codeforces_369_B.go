
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	l, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	sAll, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	sk, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	ans := getPoints(n, k, l, r, sAll, sk)
	for _, num := range ans {
		fmt.Printf("%d ", num)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		ans[i] = l
	}
	sAll -= sk + (n - k) * l
	sk -= k * l
	for sk > 0 {
		idx := n - 1
		for idx >= n-k && sk > 0 {
			ans[idx]++
			sk--
			idx--
		}
	}
	for sAll > 0 {
		idx := 0
		for idx < n-k && sAll > 0 {
			ans[idx]++
			sAll--
			idx++
		}
	}
	return ans
}

// 