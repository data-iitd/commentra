
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MOD = 100000007
	const INF = int(1e18)

	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 101000)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	x := nextInt(sc)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
	}

	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + a[i]
	}

	ans := INF
	for k := 1; k <= n/3; k++ {
		e := k*x + 2*sum(s, n-2*k-1, -k)
		ans = Min(ans, e)
	}

	fmt.Println(ans + n*x + 5*s[n])
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func Min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func sum(s []int, l, d int) int {
	if l < 0 {
		return 0
	}
	return s[l] - s[l-d]
}

