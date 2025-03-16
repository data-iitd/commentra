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
	beacon := make([]int, 1000001)
	dp := make([]int, 1000001)
	for i := 0; i < n; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		beacon[a], _ = strconv.Atoi(sc.Text())
	}
	if beacon[0]!= 0 {
		dp[0] = 1
	}
	for i := 1; i < 1000001; i++ {
		if beacon[i]!= 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i]!= 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
	}
	max := 0
	for i := 0; i < 1000001; i++ {
		if max < dp[i] {
			max = dp[i]
		}
	}
	fmt.Println(n - max)
}

