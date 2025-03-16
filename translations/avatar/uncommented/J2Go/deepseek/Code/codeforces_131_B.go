package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	
	const N = 1e5 + 5
	var cnt [21]int
	
	for i := 0; i < n; i++ {
		scanner.Scan()
		val := 0
		fmt.Sscan(scanner.Text(), &val)
		cnt[val+10]++
	}
	
	var res int64
	for i := 0; i < 10; i++ {
		res += int64(cnt[i]) * int64(cnt[20-i])
	}
	res += int64(cnt[10]) * int64(cnt[10] - 1) / 2
	fmt.Println(res)
}
