package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := toInt(scanner.Text())
	scanner.Scan()
	M := toInt(scanner.Text())

	H := make([]int64, N)
	ans := make([]bool, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		H[i] = toInt64(scanner.Text())
		ans[i] = true
	}

	for query := 0; query < M; query++ {
		scanner.Scan()
		temp1 := toInt(scanner.Text()) - 1
		scanner.Scan()
		temp2 := toInt(scanner.Text()) - 1

		if H[temp1] < H[temp2] {
			ans[temp1] = false
		} else if H[temp1] > H[temp2] {
			ans[temp2] = false
		} else {
			ans[temp1] = false
			ans[temp2] = false
		}
	}

	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++
		}
	}

	fmt.Println(ans2)
}

func toInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

func toInt64(s string) int64 {
	var res int64
	fmt.Sscanf(s, "%d", &res)
	return res
}

