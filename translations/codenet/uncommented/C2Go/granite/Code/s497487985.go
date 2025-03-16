
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

func compare_int(a, b int) int {
	return b - a
}

// 公約数
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

// 最小公倍数 = a * b / 最大公约数
// 公倍数
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	sc.Buffer(make([]byte, initialBufSize), maxBufSize)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	k := nextInt64(sc)
	q := nextInt(sc)

	a := make([]int, q)
	point := make([]int64, n)

	for i := 0; i < q; i++ {
		a[i] = nextInt(sc)
		point[a[i]-1]++
	}

	for i := 0; i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	i, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return i
}

func min(x, y int) int {
	return x * y / gcd(x, y)
}

func max(x, y int) int {
	return x * y / gcd(x, y)
}

