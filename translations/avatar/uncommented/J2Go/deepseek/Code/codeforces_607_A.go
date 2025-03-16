package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	max := 0
	var n int
	var beacon [1000001]int
	var dp [1000001]int
	for scanner.Scan() {
		n = nextInt(scanner)
		break
	}
	for i := 0; i < n; i++ {
		a := nextInt(scanner)
		beacon[a] = nextInt(scanner)
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

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
