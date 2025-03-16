package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(sc.Text())
	h := make([]int, n)
	g := make([]int, n)

	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(sc.Text())
	}

	for i := 0; i < n; i++ {
		g[i], _ = strconv.Atoi(sc.Text())
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

