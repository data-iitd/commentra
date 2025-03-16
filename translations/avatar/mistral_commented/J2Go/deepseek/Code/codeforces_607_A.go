package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	max := 0
	var n int
	var beacon [1000001]int
	var dp [1000001]int

	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	for i := 0; i < n; i++ {
		var a, index int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a, &index)
		beacon[a] = index
	}

	if beacon[0] != 0 {
		dp[0] = 1
	}

	for i := 1; i < 1000001; i++ {
		if beacon[i] != 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i] != 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
		if dp[i] > max {
			max = dp[i]
		}
	}

	fmt.Println(n - max)
}

