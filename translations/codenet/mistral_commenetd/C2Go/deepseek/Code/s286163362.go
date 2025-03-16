package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		input := scanner.Text()
		parts := strings.Fields(input)
		n, _ := strconv.Atoi(parts[0])
		k, _ := strconv.Atoi(parts[1])
		if n == 0 && k == 0 {
			break
		}

		data := make([]int, 111111)
		seq := make([]int, 222222)

		for i := 0; i < k; i++ {
			scanner.Scan()
			t, _ := strconv.Atoi(scanner.Text())
			data[t]++
		}

		p := 0
		for i := 1; i <= n; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		ret := 0
		if data[0] > 0 {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		fmt.Println(ret)
	}
}
