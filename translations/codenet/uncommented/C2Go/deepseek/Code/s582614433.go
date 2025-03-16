package main

import (
	"fmt"
	"sort"
	"strconv"
)

type Edge struct {
	p  int
	i  int
	s  string
}

func main() {
	var n int
	fmt.Scan(&n)
	data := make([]Edge, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i].s, &data[i].p)
		data[i].i = i + 1
	}
	sort.Slice(data, func(i, j int) bool {
		if data[i].s == data[j].s {
			return data[i].p > data[j].p
		}
		return data[i].s < data[j].s
	})
	for _, edge := range data {
		fmt.Println(edge.i)
	}
}

