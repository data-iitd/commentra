package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	if n != 1 {
		fmt.Println("Error: Expected exactly one integer input for n, but got", n)
		return
	}

	const N = 1e5 + 5
	var cnt [21]int

	scanner.Scan()
	for i := 0; i < n; i++ {
		var x int
		fmt.Sscan(scanner.Text(), &x)
		cnt[x+10]++
	}

	var res int64

	for i := 0; i < 10; i++ {
		res += int64(cnt[i]) * int64(cnt[20-i])
	}

	res += int64(cnt[10]) * int64(cnt[10]-1) / 2

	fmt.Println(res)
}
