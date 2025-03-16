package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 2)
	sc[0], _ = strconv.Atoi(os.Args[1])
	sc[1], _ = strconv.Atoi(os.Args[2])
	n := sc[0]
	m := sc[1]
	if n == 0 {
		if m != 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println(0 + " " + 0)
		}
		return
	}
	if m <= n {
		if m == 0 {
			m = 1
		}
		fmt.Println(n + " " + (m + n - 1))
		return
	}
	fmt.Println(m + " " + (m + n - 1))
}

