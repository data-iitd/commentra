
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	for {
		n, _ := strconv.Atoi(read(r))
		if n == 0 {
			break
		}
		r, _ := strconv.Atoi(read(r))
		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}
		for i := 0; i < r; i++ {
			p, _ := strconv.Atoi(read(r))
			c, _ := strconv.Atoi(read(r))
			b := make([]int, c)
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}
			for j := 0; j < p-1; j++ {
				a[n-p-c+1+j] = a[n-p+j+1]
			}
			for j := n - p - c + 1 + j, k := 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}
		}
		fmt.Println(a[n-1])
	}
}

func read(r *bufio.Reader) string {
	str, _, _ := r.ReadLine()
	return string(str)
}

