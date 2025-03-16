package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of test cases")
	tc, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the two numbers")
		a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		fmt.Println(sub(a, b))
	}
}

func sub(a, b int) int {
	min := a
	if b < a {
		min = b
	}
	max := a
	if b > a {
		max = b
	}
	result := 0
	for min > 0 {
		result += max / min
		max = max % min
		curr_min := min
		curr_max := max
		if curr_min > curr_max {
			curr_min = curr_max
		}
		if curr_max > curr_min {
			curr_max = curr_min
		}
		min = curr_min
		max = curr_max
	}
	return result
}

