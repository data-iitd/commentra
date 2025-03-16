
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type pair struct {
	first  int
	second string
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	for scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
		if n == 0 {
			break
		}
		m := make([][]int, 33)
		for i := 0; i < n; i++ {
			name := ""
			for scanner.Scan() {
				if scanner.Text() == "#" {
					break
				}
				name += scanner.Text() + " "
			}
			count := 0
			for scanner.Scan() {
				if scanner.Text() == "#" {
					break
				}
				a, _ := strconv.Atoi(scanner.Text())
				m[a] = append(m[a], i)
				count += n - len(m[a])
			}
			fmt.Printf("%d %s\n", count, strings.TrimSpace(name))
		}
	}
}

