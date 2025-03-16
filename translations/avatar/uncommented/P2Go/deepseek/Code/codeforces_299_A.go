package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	num, _ := strconv.Atoi(input)
	return num
}

func readIntArray() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	intParts := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		intParts = append(intParts, num)
	}
	return intParts
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	lines := []string{}
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	if len(lines) < 2 {
		return
	}
	nums := []int{}
	for _, numStr := range strings.Split(lines[1], " ") {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}
	sort.Ints(nums)
	if any(func(x int) bool { return x%nums[0] != 0 }, nums) {
		fmt.Println(nums[0])
	} else {
		fmt.Println(-1)
	}
}

func any(f func(int) bool, nums []int) bool {
	for _, num := range nums {
		if f(num) {
			return true
		}
	}
	return false
}
