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
	fmt.Println("Enter the time interval:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	sec, _ := strconv.Atoi(input)
	fmt.Println("Enter the number to be added per iteration:")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	per_num, _ := strconv.Atoi(input)
	fmt.Println("Enter the maximum time:")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	max_sec, _ := strconv.Atoi(input)
	max_sec += 0.5
	ans_num := 0
	for i := sec; i < max_sec; i += sec {
		ans_num += per_num
	}
	fmt.Println(ans_num)
}

