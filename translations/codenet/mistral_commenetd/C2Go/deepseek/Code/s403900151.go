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
		fmt.Fscanf(reader, "%d %d\n", &n, &r)
		if n == 0 && r == 0 {
			break
		}

		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}

		for i := 0; i < r; i++ {
			var p, c int
			fmt.Fscanf(reader, "%d %d\n", &p, &c)

			b := make([]int, c)
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			for j := 0; j < p-1; j++ {
				a[n-p+j+1] = a[n-p+j]
			}

			for j, k := n-p-c+1, 0; j < n; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			fmt.Println(a[n-1])
		}
	}
}

