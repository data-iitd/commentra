
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.ParseInt(reader.ReadLine(), 10, 64)
	}
	const mod = 100000007
	ans := int64(0)
	for i := 0; i < 60; i++ {
		count1 := int64(0)
		for j := 0; j < n; j++ {
			if a[j]&(1<<uint(i))!= 0 {
				count1++
			}
		}
		tmp := count1 * (n - count1)
		for j := 0; j < i; j++ {
			tmp = (tmp << 1) % mod
		}
		ans = (ans + tmp) % mod
	}
	fmt.Println(ans)
}

