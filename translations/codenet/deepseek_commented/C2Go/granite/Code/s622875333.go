
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	var r int
	for scanner.Scan() {
		text := scanner.Text()
		if n == 0 && r == 0 {
			break
		}
		n, _ = strconv.Atoi(text)
		if!scanner.Scan() {
			break
		}
		text = scanner.Text()
		r, _ = strconv.Atoi(text)
		if n == 0 && r == 0 {
			break
		}
		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = n - i
		}
		for i := 0; i < r; i++ {
			b := make([]int, n)
			copy(b, a)
			var p int
			var c int
			if!scanner.Scan() {
				break
			}
			text = scanner.Text()
			p, _ = strconv.Atoi(text)
			if!scanner.Scan() {
				break
			}
			text = scanner.Text()
			c, _ = strconv.Atoi(text)
			for j := 0; j < c; j++ {
				a[j] = b[p-1+j]
			}
			for j := c; j < c+p-1; j++ {
				a[j] = b[j-c]
			}
		}
		fmt.Println(a[0])
	}
}

