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
	sc.Scan()
	b, _ := strconv.Atoi(sc.Text())
	ans := make([]int, n)
	q := make([]int, 0)
	for i := 0; i < n; i++ {
		sc.Scan()
		t, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		d, _ := strconv.Atoi(sc.Text())
		for len(q) > 0 && q[0] <= t {
			q = q[1:]
		}
		if len(q) <= b {
			if len(q) == 0 {
				ans[i] = t + d
			} else {
				ans[i] = q[len(q)-1] + d
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

