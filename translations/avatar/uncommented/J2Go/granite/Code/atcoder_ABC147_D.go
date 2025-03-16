
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	div := int64(1e9 + 7)
	a := make([]int64, n)
	ans := int64(0)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	for i := 0; i < 60; i++ {
		count1 := int64(0)
		for j := 0; j < n; j++ {
			if (a[j]>>i)&1 == 1 {
				count1++
			}
		}
		a := (a + count1*(n-count1)) % div
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}
		ans += a
		ans %= div
	}
	fmt.Println(ans)
}

