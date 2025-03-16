package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := parseInt(scanner.Text())

	a := make([]int, n)
	acc := make([]int, n+1)

	scanner.Scan()
	for i := 0; i < n; i++ {
		a[i] = parseInt(scanner.Text())
		acc[i+1] = acc[i] + a[i]
		acc[i+1] %= MOD
	}

	var ans int
	for i := 0; i < n; i++ {
		temp := a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD
		ans += temp
		ans %= MOD
	}

	fmt.Println(ans)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

