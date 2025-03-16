package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	input := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(input.Text())
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(input.Text())
		m[val]++
	}
	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	fmt.Println(max, len(m))
}

