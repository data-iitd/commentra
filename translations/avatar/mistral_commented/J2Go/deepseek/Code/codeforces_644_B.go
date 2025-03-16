package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())

	ans := make([]int64, n)
	q := []int64{}

	for i := 0; i < n; i++ {
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		d, _ := strconv.Atoi(scanner.Text())

		for len(q) > 0 && q[0] <= int64(t) {
			q = q[1:]
		}

		if len(q) <= b {
			if len(q) == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q[len(q)-1] + int64(d)
			}
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}

	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
}

