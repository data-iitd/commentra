package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	input := "1 2 3 4 5 6 7 8 9 10"
	fmt.Println(nPairsWithCommonFX(strings.Split(input, " ")))
}

func nPairsWithCommonFX(sequence []string) int {
	storage := make(map[int][]int)
	FXs := make([]int, 0)
	for _, value := range sequence {
		y := f(value)
		if _, ok := storage[y]; !ok {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			storage[y] = append(storage[y], value)
		}
	}
	sum := 0
	for _, y := range FXs {
		sum += len(storage[y]) * (len(storage[y]) - 1)
	}
	return sum / 2
}

func f(n string) int {
	y := 1
	for n != "1" {
		if n[len(n)-1:] == "1" {
			y++
		}
		n = n[:len(n)-1]
	}
	return y
}

// 