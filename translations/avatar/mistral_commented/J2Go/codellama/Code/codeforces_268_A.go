
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	h := make([]int, n)
	g := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		h[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		g[i], _ = strconv.Atoi(scanner.Text())
	}

	result := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				result++
			}
		}
	}

	fmt.Println(result)
}

