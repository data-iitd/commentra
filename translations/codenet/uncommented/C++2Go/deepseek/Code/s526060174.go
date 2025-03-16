package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	var k, a int
	var x [31]int

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &m)

	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &k)
		for j := 0; j < k; j++ {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &a)
			x[a]++
		}
	}

	ans := 0
	for i := 1; i <= m; i++ {
		if x[i] == n {
			ans++
		}
	}
	fmt.Println(ans)
}

