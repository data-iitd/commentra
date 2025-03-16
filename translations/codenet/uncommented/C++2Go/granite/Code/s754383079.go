
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	a = strings.TrimSpace(a)
	b, _ := reader.ReadString('\n')
	b = strings.TrimSpace(b)
	n := len(a)
	m := len(b)
	ans := 1000000000
	for i := 0; i <= n-m; i++ {
		sum := 0
		for j := 0; j < m; j++ {
			if a[i+j]!= b[j] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}
	fmt.Println(ans)
}

