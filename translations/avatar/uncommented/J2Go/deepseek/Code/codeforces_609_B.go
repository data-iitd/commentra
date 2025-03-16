package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)

	var n, m int
	in.Scan()
	n = atoi(in.Text())
	in.Scan()
	m = atoi(in.Text())

	arr := make([]int, n)
	gen := make([]int, 11)

	for i := 0; i < n; i++ {
		in.Scan()
		arr[i] = atoi(in.Text())
		gen[arr[i]]++
	}

	var ans int64 = 0
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	fmt.Println(ans / 2)
}

func atoi(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

