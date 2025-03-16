package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	nums := strings.Split(input, " ")

	x, _ := strconv.Atoi(nums[0])
	y, _ := strconv.Atoi(nums[1])
	a, _ := strconv.Atoi(nums[2])
	b, _ := strconv.Atoi(nums[3])

	var games [][]int

	for i := a; i <= x; i++ {
		if i <= b {
			continue
		}
		for j := b; j <= y; j++ {
			if i > j {
				games = append(games, []int{i, j})
			}
		}
	}

	fmt.Println(len(games))
	for _, pair := range games {
		fmt.Println(strconv.Itoa(pair[0]) + " " + strconv.Itoa(pair[1]))
	}
}

