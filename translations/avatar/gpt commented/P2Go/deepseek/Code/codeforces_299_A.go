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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	lines := strings.Split(line, "\n")
	
	// Read the first line and convert it to an integer
	firstLine := lines[0]
	
	// Read the second line and split it into a list of integers
	secondLine := lines[1]
	numsStr := strings.Split(secondLine, " ")
	var nums []int
	for _, numStr := range numsStr {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}
	
	// Sort the list of integers
	sort.Ints(nums)
	
	// Check if any element in the list 'nums' is not divisible by the first element of 'nums'
	// If all elements are divisible, print the first element; otherwise, print -1
	if nums[0] == 0 {
		fmt.Println(-1)
	} else {
		divisible := true
		for _, num := range nums {
			if num % nums[0] != 0 {
				divisible = false
				break
			}
		}
		if divisible {
			fmt.Println(nums[0])
		} else {
			fmt.Println(-1)
		}
	}
}
