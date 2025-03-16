package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	T, _ := strconv.Atoi(sc.Text())
	AB := make([][]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		AB[i] = []int{a, b}
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
	fmt.Println(max(dp[N]))
}

func max(a []int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > m {
			m = a[i]
		}
	}
	return m
}

