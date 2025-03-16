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
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	numbers := strings.Fields(input)
	var list []int

	for _, numStr := range numbers {
		num, _ := strconv.Atoi(numStr)
		list = append(list, num%2)
	}

	if sum(list) == 1 {
		for i, v := range list {
			if v == 1 {
				fmt.Println(i + 1)
				break
			}
		}
	} else {
		for i, v := range list {
			if v == 0 {
				fmt.Println(i + 1)
				break
			}
		}
	}
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}
