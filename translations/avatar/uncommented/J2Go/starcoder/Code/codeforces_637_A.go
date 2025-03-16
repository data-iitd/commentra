package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	ara := make([]int, n)
	for i := 0; i < n; i++ {
		var v int
		fmt.Fscan(reader, &v)
		ara[i] = v
	}
	max := 0
	for _, i := range ara {
		if i > max {
			max = i
		}
	}
	mm := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]];!ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Fprintln(writer, ara[i])
				break
			}
		} else {
			mm[ara[i]] += 1
			if mm[ara[i]] == max {
				fmt.Fprintln(writer, ara[i])
				break
			}
		}
	}
}

// 