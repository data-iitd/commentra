package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInts() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	var result []int
	for _, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		result = append(result, num)
	}
	return result, nil
}

func main() {
	nums, err := readInts()
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	n := nums[0]
	m := nums[1]

	lst, err := readInts()
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	l := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, exists := l[lst[i]]; !exists {
			l[lst[i]] = 1
		} else {
			l[lst[i]] += 1
		}
	}

	res := 0
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]] -= 1
		} else {
			res += n - i - 1
		}
	}

	fmt.Println(res)
}
