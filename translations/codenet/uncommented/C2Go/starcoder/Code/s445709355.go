// ABC 152-D
// 2020.1.19 bal4u

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		N int
		i int
	)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
		if N == 0 {
			break
		}
		var (
			f1 [100]int
			f2 [100]int
		)
		for i = 0; i < 100; i++ {
			f1[i] = 0
			f2[i] = 0
		}
		for i = 0; i < N; i++ {
			n := N - i - 1
			k := n % 10
			n /= 10
			f1[10*k+n]++
			f2[n*10+k]++
		}
		ans := 0
		for i = 0; i < 100; i++ {
			ans += f1[i] * f2[i]
		}
		fmt.Println(ans)
	}
}

