
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 0)
	for _, arg := range os.Args[1:] {
		i, err := strconv.Atoi(arg)
		if err != nil {
			fmt.Println(err)
			return
		}
		sc = append(sc, i)
	}
	n := sc[0]
	m := sc[1]
	uf := make([]int, n)
	for i := 0; i < n; i++ {
		uf[i] = i
	}
	for i := 0; i < m; i++ {
		x := sc[2*i+2] - 1
		y := sc[2*i+3] - 1
		z := sc[2*i+4]
		uf[x] = y
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if uf[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

