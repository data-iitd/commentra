
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		a, _ := strconv.Atoi(scanner.Text())
		if err := scanner.Err(); err!= nil {
			fmt.Fprintln(os.Stderr, "reading standard input:", err)
		}
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
		if err := scanner.Err(); err!= nil {
			fmt.Fprintln(os.Stderr, "reading standard input:", err)
		}
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		if err := scanner.Err(); err!= nil {
			fmt.Fprintln(os.Stderr, "reading standard input:", err)
		}
		a %= b
		sum := 0
		for i := 1; i <= n; i++ {
			a *= 10
			for j := 9; j >= 0; j-- {
				if b*j <= a {
					break
				}
			}
			a -= b * j
			sum += j
		}
		fmt.Println(sum)
	}
}

