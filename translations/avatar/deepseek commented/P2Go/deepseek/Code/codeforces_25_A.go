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
	numsStr := strings.Fields(input)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(numsStr[i])
		nums[i] = nums[i] % 2
	}

	sum := 0
	for _, num := range nums {
		sum += num
	}

	if sum == 1 {
		for i, num := range nums {
			if num == 1 {
				fmt.Println(i + 1)
				break
			}
		}
	} else {
		for i, num := range nums {
			if num == 0 {
				fmt.Println(i + 1)
				break
			}
		}
	}
}

