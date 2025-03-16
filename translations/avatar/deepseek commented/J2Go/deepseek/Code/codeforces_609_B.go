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
	n := parseInt(scanner.Text())
	scanner.Scan()
	m := parseInt(scanner.Text())

	arr := make([]int, n)
	gen := make([]int, 11)

	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i] = parseInt(scanner.Text())
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

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

