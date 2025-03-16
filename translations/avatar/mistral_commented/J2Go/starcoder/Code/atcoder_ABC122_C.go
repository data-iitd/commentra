
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

	var n, q int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	q, _ = strconv.Atoi(sc.Text())

	s := make([]byte, n)
	sc.Scan()
	s = []byte(sc.Text())

	var range_ [][]int
	for i := 0; i < q; i++ {
		var left, right int
		sc.Scan()
		left, _ = strconv.Atoi(sc.Text())
		sc.Scan()
		right, _ = strconv.Atoi(sc.Text())
		range_ = append(range_, []int{left, right})
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)

	for i := 2; i <= n; i++ {
		if s[i-2] == 'A' && s[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for _, v := range range_ {
		left := v[0]
		right := v[1]
		fmt.Println(rui[right] - rui[left])
	}
}

