package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	inf = 10000000000000000000
	mod = 1000000007
)

var dd = [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
var ddn = [][]int{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		ints = append(ints, num)
	}
	return ints
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readFloat() float64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	c, _ := strconv.Atoi(parts[2])
	d, _ := strconv.Atoi(parts[3])

	result := max(a*c, b*d, a*d, b*c)
	fmt.Println(result)
}

func max(nums ...int) int {
	maxNum := nums[0]
	for _, num := range nums {
		if num > maxNum {
			maxNum = num
		}
	}
	return maxNum
}

