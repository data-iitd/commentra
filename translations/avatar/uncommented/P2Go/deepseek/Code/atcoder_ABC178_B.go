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
	line, _ := reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(line), " ")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	c, _ := strconv.Atoi(nums[2])
	d, _ := strconv.Atoi(nums[3])

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	result := max(max(a*c, b*d), max(a*d, b*c))
	fmt.Println(result)
}
