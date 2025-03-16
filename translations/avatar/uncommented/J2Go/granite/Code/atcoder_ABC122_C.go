
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n, q int
	sc.Scan()
	n = int(mustParseInt(sc.Text()))
	sc.Scan()
	q = int(mustParseInt(sc.Text()))
	s := mustParseString(sc.Text())
	r := make([][]int, q)
	for i := 0; i < q; i++ {
		sc.Scan()
		l := int(mustParseInt(sc.Text()))
		sc.Scan()
		r[i] = []int{l - 1, int(mustParseInt(sc.Text()))}
	}
	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 1; i < n; i++ {
		if s[i-1:i+1] == "AC" {
			frag[i+1]++
		}
		rui[i+1] = rui[i] + frag[i+1]
	}
	for _, v := range r {
		l, r := v[0], v[1]
		fmt.Println(rui[r] - rui[l])
	}
}

func mustParseInt(s string) int {
	n, err := parseInt(s)
	if err!= nil {
		panic(err)
	}
	return n
}

func mustParseString(s string) string {
	return s
}

func parseInt(s string) (int, error) {
	return strconv.Atoi(s)
}

// 