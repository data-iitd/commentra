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

func readIntList() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	nums := strings.Split(input, " ")
	intNums := make([]int, len(nums))
	for i, num := range nums {
		intNum, _ := strconv.Atoi(num)
		intNums[i] = intNum
	}
	return intNums
}

func readIntMap() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	nums := strings.Split(input, " ")
	intNums := make([]int, len(nums))
	for i, num := range nums {
		intNum, _ := strconv.Atoi(num)
		intNums[i] = intNum
	}
	return intNums
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	lines := strings.Split(input, "\n")
	sortedNums := readIntList()
	sort.Ints(sortedNums)

	if any(func(x int) bool { return sortedNums[0] % x == 0 }, sortedNums) {
		fmt.Println(sortedNums[0])
	} else {
		fmt.Println(-1)
	}
}

func any(f func(int) bool, list []int) bool {
	for _, x := range list {
		if f(x) {
			return true
		}
	}
	return false
}
