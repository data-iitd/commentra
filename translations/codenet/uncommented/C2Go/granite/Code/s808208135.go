
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func main() {
	var i, j, k, u int
	var err error
	var reader = bufio.NewReader(os.Stdin)

	if n, err = strconv.Atoi(readLine(reader)); err!= nil {
		panic(err)
	}

	for i = 0; i < n; i++ {
		if u, err = strconv.Atoi(readLine(reader)); err!= nil {
			panic(err)
		}
		if k, err = strconv.Atoi(readLine(reader)); err!= nil {
			panic(err)
		}
		for j = 0; j < k; j++ {
			if a[count].back, err = strconv.Atoi(readLine(reader)); err!= nil {
				panic(err)
			}
			if a[count].go, err = strconv.Atoi(readLine(reader)); err!= nil {
				panic(err)
			}
			if a[count].cost, err = strconv.Atoi(readLine(reader)); err!= nil {
				panic(err)
			}
			count++
		}
	}
	root(count)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

func root(b int) {
	var i, flag int = 0, 1

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

func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

