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
	sc.Scan()
	k, _ := strconv.Atoi(sc.Text())
	bb := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		bb[i], _ = strconv.Atoi(sc.Text())
	}
	aa := make([]int, n)
	m := 0
	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := m + 1; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		m++
	}
	for i := 0; i < n; i++ {
		fmt.Print(aa[i]+1, " ")
	}
	fmt.Println()
}

