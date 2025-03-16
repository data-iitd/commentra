

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	x := make([]int, 3)
	max := 0
	for i := 0; i < 3; i++ {
		x[i] = nextInt(sc)
		max = max(max, x[i])
	}
	k := nextInt(sc)
	sc.Scan()
	a := make([][]int64, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < x[i]; j++ {
			a[i][j] = nextInt64(sc)
		}
		sort.Slice(a[i], func(i, j int) bool {
			return a[i][j] < a[i][j]
		})
	}

	ans := make([]int64, 0)
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})
	for i := 0; i < k; i++ {
		fmt.Println(ans[len(ans)-i-1])
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

