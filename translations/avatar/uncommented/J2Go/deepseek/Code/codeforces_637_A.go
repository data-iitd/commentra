package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)

	in.Scan()
	n, _ := fmt.Sscanf(in.Text(), "%d", &n)
	ara := make([]int, n)
	mm := make(map[int]int)

	for i := 0; i < n; i++ {
		in.Scan()
		v, _ := fmt.Sscanf(in.Text(), "%d", &v)
		ara[i] = v
		if _, ok := mm[v]; !ok {
			mm[v] = 1
		} else {
			mm[v]++
		}
	}

	max := 0
	for _, value := range mm {
		if value > max {
			max = value
		}
	}

	mm = make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]]; !ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Fprintln(pw, ara[i])
				break
			}
		} else {
			mm[ara[i]]++
			if mm[ara[i]] == max {
				fmt.Fprintln(pw, ara[i])
				break
			}
		}
	}

	pw.Flush()
}

