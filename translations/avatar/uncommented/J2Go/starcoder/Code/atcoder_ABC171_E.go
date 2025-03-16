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
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	a := make([]int, n)
	r := 0
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
		r ^= a[i]
	}
	for i := 0; i < n; i++ {
		if i!= 0 {
			fmt.Print(" ")
		}
		fmt.Print(r ^ a[i])
	}
}

