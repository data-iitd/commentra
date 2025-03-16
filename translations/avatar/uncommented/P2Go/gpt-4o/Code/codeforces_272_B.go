package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Read the first line (not used)
	fmt.Scanln(&input) // Read the second line with numbers
	sequence := parseInput(input)
	fmt.Println(nPairsWithCommonFX(sequence))
}

func parseInput(input string) []int {
	strs := strings.Split(input, " ")
	sequence := make([]int, len(strs))
	for i, s := range strs {
		num, _ := strconv.Atoi(s)
		sequence[i] = num
	}
	return sequence
}

func nPairsWithCommonFX(sequence []int) int {
	storage := make(map[int][]int)
	FXs := []int{}

	for _, value := range sequence {
		y := f(value)
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			storage[y] = append(storage[y], value)
		}
	}

	totalPairs := 0
	for _, y := range FXs {
		count := len(storage[y])
		totalPairs += count * count
	}

	totalCount := 0
	for _, y := range FXs {
		totalCount += len(storage[y])
	}

	return (totalPairs - totalCount) / 2
}

func f(n int) int {
	y := 1
	for n != 1 {
		if n%2 != 0 {
			y++
		}
		n /= 2
	}
	return y
}

// <END-OF-CODE>
