package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	n := nPairsWithCommonFX(toIntSlice(input))
	fmt.Println(n)
}

func nPairsWithCommonFX(sequence []int) int {
	storage := make(map[int][]int)
	var FXs []int
	for _, value := range sequence {
		y := f(value)
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			storage[y] = append(storage[y], value)
		}
	}
	return (sum(len(storage[y])*len(storage[y]) for y := range storage) - sum(len(storage[y]) for y := range storage)) / 2
}

func f(n int) int {
	y := 1
	for n != 1 {
		if n%2 != 0 {
			y += 1
		}
		n /= 2
	}
	return y
}

func toIntSlice(input string) []int {
	ints := []int{}
	for _, s := range input {
		i, err := strconv.Atoi(string(s))
		if err == nil {
			ints = append(ints, i)
		}
	}
	return ints
}

func sum(values ...int) int {
	total := 0
	for _, v := range values {
		total += v
	}
	return total
}
