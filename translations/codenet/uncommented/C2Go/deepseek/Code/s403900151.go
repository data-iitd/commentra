package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		var n, r int
		fmt.Fscan(reader, &n, &r)
		if n == 0 && r == 0 {
			break
		}

		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}

		for i := 0; i < r; i++ {
			var p, c int
			fmt.Fscan(reader, &p, &c)

			b := make([]int, c)
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}
			for j := 0; j < p-1; j++ {
				a[n-p-c+1+j] = a[n-p+j+1]
			}
			for j, k := n-p-c+1+p-1, 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}
		}
		fmt.Println(a[n-1])
	}
}

