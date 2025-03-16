package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	in.Scan()
	fmt.Sscan(in.Text(), &n)

	ara := make([]int, n)
	mm := make(map[int]int)

	for i := 0; i < n; i++ {
		in.Scan()
		v := 0
		fmt.Sscan(in.Text(), &v)
		ara[i] = v
		mm[v]++
	}

	max := 0
	for _, count := range mm {
		if count > max {
			max = count
		}
	}

	mm = make(map[int]int)
	for i := 0; i < n; i++ {
		if _, exists := mm[ara[i]]; !exists {
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
}

