
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	N    = 100000
	INF  = 1000000
	SIZE = 500000
)

type Date struct {
	go    int
	back  int
	cost  int
}

var (
	n, d [N]int
	a     [SIZE]Date
)

func main() {
	var (
		i, j, k, u, count int
	)
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" {
			break
		}
		fields := len(text)
		if fields == 0 {
			continue
		}
		if fields == 1 {
			n, _ = strconv.Atoi(text)
			continue
		}
		fields = len(text)
		if fields == 2 {
			u, _ = strconv.Atoi(text)
			continue
		}
		k, _ = strconv.Atoi(text)
		for j = 0; j < k; j++ {
			a[count].back = u
			text, _ = scanner.Scan()
			fields = len(text)
			if fields == 0 {
				continue
			}
			a[count].go, _ = strconv.Atoi(text)
			text, _ = scanner.Scan()
			fields = len(text)
			if fields == 0 {
				continue
			}
			a[count].cost, _ = strconv.Atoi(text)
			count++
		}
	}
	root(count)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d\n", i, d[i])
	}
}

func root(b int) {
	var (
		i, flag int
	)
	for i = 0; i < n; i++ {
		d[i] = INF
	}
	d[0] = 0
	for {
		flag = 0
		for i = 0; i < b; i++ {
			if a[i].cost+d[a[i].back] < d[a[i].go] {
				d[a[i].go] = a[i].cost + d[a[i].back]
				flag = 1
			}
		}
		if flag == 0 {
			break
		}
	}
}

// END-OF-CODE