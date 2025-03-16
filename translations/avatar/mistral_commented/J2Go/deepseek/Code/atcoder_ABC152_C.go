package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	fmt.Println(solve())
}

func solve() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := toInt(scanner.Text())

	arr := make([]int, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i] = toInt(scanner.Text())
	}

	sort.Ints(arr)

	sum := 0
	var q []int

	for i := 0; i < len(arr); i++ {
		q = append(q, arr[i])
		sort.Ints(q)
		if arr[i] <= q[0] {
			sum++
		}
	}

	return sum
}

func toInt(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}

