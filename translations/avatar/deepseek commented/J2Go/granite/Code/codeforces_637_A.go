
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	n, _ := strconv.Atoi(in.ReadLine())
	ara := make([]int, n)
	map := make(map[int]int)

	for i := 0; i < n; i++ {
		v, _ := strconv.Atoi(in.ReadLine())
		ara[i] = v
		if _, ok := map[v];!ok {
			map[v] = 1
		} else {
			map[v]++
		}
	}

	max := 0
	for _, i := range map {
		if i > max {
			max = i
		}
	}

	mm := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]];!ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Fprintln(out, ara[i])
				break
			}
		} else {
			mm[ara[i]]++
			if mm[ara[i]] == max {
				fmt.Fprintln(out, ara[i])
				break
			}
		}
	}

	out.Flush()
}

// 