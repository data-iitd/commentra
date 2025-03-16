
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r, g, b, n := 0, 0, 0, 0
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d %d\n", &r, &g, &b, &n)
	ans := 0
	for i := 0; i <= n/r; i++ {
		for j := 0; j <= n/g; j++ {
			num := n - r*i - g*j
			if num >= 0 && num%b == 0 {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

