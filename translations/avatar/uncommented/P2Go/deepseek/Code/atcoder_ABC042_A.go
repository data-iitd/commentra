package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	var ABC [3]int
	for i := 0; i < 3; i++ {
		ABC[i], _ = strconv.Atoi(parts[i])
	}
	if strings.Count(input, "5") == 2 {
		if sum(ABC[:]) == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}

func sum(nums []int) int {
	total := 0
	for _, num := range nums {
		total += num
	}
	return total
}
