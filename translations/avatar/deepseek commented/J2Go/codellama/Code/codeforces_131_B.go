
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	cnt := make([]int, 21)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x+10]++
	}
	res := 0
	for i := 0; i < 10; i++ {
		res += int(cnt[i]) * cnt[20-i]
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2
	fmt.Println(res)
}

