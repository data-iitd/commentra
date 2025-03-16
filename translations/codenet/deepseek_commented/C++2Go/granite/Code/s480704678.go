
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	acc := make([]int, n+1)
	for i := 0; i < n; i++ {
		acc[i+1] = (acc[i] + a[i]) % 1000000007
	}

	ans := 0
	for i := 0; i < n; i++ {
		ans = (ans + a[i]*(1000000007+acc[n]-acc[i+1])) % 1000000007
	}
	fmt.Println(ans)
}

