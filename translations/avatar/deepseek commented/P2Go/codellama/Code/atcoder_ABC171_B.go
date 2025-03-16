package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var numbers []int
	fmt.Scan(&numbers)
	numbers = strings.Split(numbers, " ")

	for i := 0; i < len(numbers); i++ {
		numbers[i], _ = strconv.Atoi(numbers[i])
	}

	sort.Ints(numbers)

	var sum int
	for i := 0; i < k; i++ {
		sum += numbers[i]
	}

	fmt.Println(sum)
}

