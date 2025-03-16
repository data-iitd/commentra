
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	n_int, _ := strconv.Atoi(n)
	cnt := make([][]int, 10)
	for i := 0; i < 10; i++ {
		cnt[i] = make([]int, 10)
	}
	for i := 1; i <= n_int; i++ {
		b := i % 10
		a := i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}
	ans := 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += cnt[i][j] * cnt[j][i]
		}
	}
	fmt.Println(ans)
}

