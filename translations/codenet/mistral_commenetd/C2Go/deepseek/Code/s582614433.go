package main

import (
	"fmt"
	"sort"
	"strconv"
)

type Edge struct {
	P   int
	I   int
	S   string
}

func main() {
	var n int
	fmt.Scan(&n)
	data := make([]Edge, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i].S, &data[i].P)
		data[i].I = i + 1
	}
	sort.Slice(data, func(i, j int) bool {
		if data[i].S != data[j].S {
			return data[i].S < data[j].S
		}
		return data[i].P > data[j].P
	})
	for _, edge := range data {
		fmt.Println(edge.I)
	}
}
