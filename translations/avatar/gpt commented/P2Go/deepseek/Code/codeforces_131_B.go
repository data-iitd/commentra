package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := parseInt(scanner.Text())
	scanner.Scan()
	words := parseIntArray(scanner.Text())
	counter := make(map[int]int)
	for _, word := range words {
		counter[word]++
	}
	count := 0
	for num, freq := range counter {
		if num == 0 {
			count += freq * (freq - 1)
		} else if freq2, found := counter[-num]; found {
			count += freq * freq2
		}
	}
	fmt.Println(count / 2)
}

func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

func parseIntArray(s string) []int {
	var nums []int
	for _, numStr := range strings.Split(s, " ") {
		nums = append(nums, parseInt(numStr))
	}
	return nums
}
