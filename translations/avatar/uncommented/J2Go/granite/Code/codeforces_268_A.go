
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine())
	h := make([]int, n)
	g := make([]int, n)
	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(reader.ReadLine())
		g[i], _ = strconv.Atoi(reader.ReadLine())
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

