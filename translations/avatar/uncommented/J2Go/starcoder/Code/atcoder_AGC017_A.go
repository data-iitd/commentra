package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func C(n, m int) *big.Int {
	res := big.NewInt(1)
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(int64(i)))
	}
	for i := 1; i <= n; i++ {
		res.Div(res, big.NewInt(int64(i)))
	}
	return res
}

func main() {
	sc := NewScanner()
	n, p := sc.nextInt(), sc.nextInt()
	k0, k1 := 0, 0
	for i := 0; i < n; i++ {
		x := sc.nextInt()
		if x%2 == 1 {
			k1++
		} else {
			k0++
		}
	}
	ans := big.NewInt(1)
	for i := 0; i < k0; i++ {
		ans.Mul(ans, big.NewInt(2))
	}
	if p == 0 {
		add := big.NewInt(0)
		for i := 0; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add)
		fmt.Println(ans)
	} else {
		add := big.NewInt(0)
		for i := 1; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add)
		fmt.Println(ans)
	}
}

type Scanner struct {
	*bufio.Scanner
}

func NewScanner() *Scanner {
	sc := new(Scanner)
	sc.Scanner = new(bufio.Scanner)
	sc.Scanner.Split(bufio.ScanWords)
	return sc
}

func (this *Scanner) nextInt() int { n, _ := this.nextInt64(); return int(n) }
func (this *Scanner) nextInt64() (int64, bool) {
	scanned, err := this.Scanner.Scan()
	if err!= nil {
		return 0, false
	}
	n, err := strconv.ParseInt(scanned, 10, 64)
	return n, err == nil
}

