

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	sc = bufio.NewScanner(os.Stdin)
)

func nextInt() int {
	sc.Scan()
	nextInt, _ := strconv.Atoi(sc.Text())
	return nextInt
}

func main() {
	N := nextInt()
	T := nextInt()

	AB := make([][]int, N)
	for i := 0; i < N; i++ {
		AB[i] = make([]int, 2)
		AB[i][0] = nextInt()
		AB[i][1] = nextInt()
	}

	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, 6001)
	}

	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			dp[i][timeAfterEat] = dp[i-1][timeAfterEat]
			time := AB[i-1][0]
			value := AB[i-1][1]
			if 0 <= timeAfterEat-time && timeAfterEat-time < T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	fmt.Println(max(dp[N]...))
}

func max(a...int) int {
	m := a[0]
	for _, v := range a {
		if m < v {
			m = v
		}
	}
	return m
}

