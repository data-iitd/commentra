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
	q, _ := strconv.Atoi(sc.Text())
	c := make([]byte, n)
	sc.Scan()
	c = []byte(sc.Text())
	range_ := make([][]int, q)
	for i := 0; i < q; i++ {
		range_[i] = make([]int, 2)
		sc.Scan()
		range_[i][0], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		range_[i][1], _ = strconv.Atoi(sc.Text())
	}
	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}
	for i := 0; i < q; i++ {
		left := range_[i][0]
		right := range_[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

