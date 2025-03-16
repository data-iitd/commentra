
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
	var n, r int
	for scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}
		for scanner.Scan() {
			r, _ = strconv.Atoi(scanner.Text())
			if r == 0 {
				break
			}
			a := make([]int, n)
			for i := 0; i < n; i++ {
				a[i] = n - i
			}
			for i := 0; i < r; i++ {
				b := make([]int, n)
				for j := 0; j < n; j++ {
					b[j] = a[j]
				}
				var p, c int
				for scanner.Scan() {
					p, _ = strconv.Atoi(scanner.Text())
					if p == 0 {
						break
					}
					for scanner.Scan() {
						c, _ = strconv.Atoi(scanner.Text())
						if c == 0 {
							break
						}
						for j := 0; j < c; j++ {
							a[j] = b[p-1+j]
						}
						for j := c; j < c+p-1; j++ {
							a[j] = b[j-c]
						}
					}
				}
				fmt.Println(a[0])
			}
		}
	}
}

