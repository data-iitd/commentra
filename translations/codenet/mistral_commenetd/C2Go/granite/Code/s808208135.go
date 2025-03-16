
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	N     = 100000
	INF   = 1000000
	limit = 500000
)

type Date struct {
	go, back, cost int
}

var (
	n, d [N]int
	a     [limit]Date
	count int
)

func root(b int) {
	var (
		i, flag int
	)
	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0
	for flag!= 0 {
		flag = 0
		for i = 0; i < b; i++ {
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = 1
			}
		}
	}
}

func main() {
	var (
		i, j, k, u int
		s           string
		st          = bufio.NewScanner(os.Stdin)
	)
	st.Scan()
	n, _ = strconv.Atoi(st.Text())
	for i = 0; i < n; i++ {
		st.Scan()
		s = st.Text()
		u, _ = strconv.Atoi(strings.Split(s, " ")[0])
		k, _ = strconv.Atoi(strings.Split(s, " ")[1])
		for j = 0; j < k; j++ {
			st.Scan()
			s = st.Text()
			a[count].back = u
			a[count].go, _ = strconv.Atoi(strings.Split(s, " ")[0])
			a[count].cost, _ = strconv.Atoi(strings.Split(s, " ")[1])
			count++
		}
	}
	root(count)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

// 