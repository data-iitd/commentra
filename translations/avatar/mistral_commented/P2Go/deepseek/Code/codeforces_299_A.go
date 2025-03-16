package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from file instead of user input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	lines := strings.Split(scanner.Text(), "\n")
	nums := []int{}
	for _, line := range lines[1:] {
		num, _ := strconv.Atoi(line)
		nums = append(nums, num)
	}
	sort.Ints(nums)

	// Find the largest number that leaves a remainder when divided by any number in the list
	largestNum := nums[0]
	hasRemainder := false
	for _, num := range nums {
		if largestNum%num != 0 {
			hasRemainder = true
			break
		}
	}

	if hasRemainder {
		fmt.Println(largestNum)
	} else {
		fmt.Println(-1)
	}
}
