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
	reader := bufio.NewReader(os.Stdin)
	a, b, c, d := readInts(reader)

	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		nums := []int{a, b, c, d}
		sort.Ints(nums)
		fmt.Println(nums[2] - nums[1])
	}
}

func readInts(reader *bufio.Reader) (int, int, int, int) {
	line, _ := reader.ReadString('\n')
	fields := strings.Fields(line)
	a, _ := strconv.Atoi(fields[0])
	b, _ := strconv.Atoi(fields[1])
	c, _ := strconv.Atoi(fields[2])
	d, _ := strconv.Atoi(fields[3])
	return a, b, c, d
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

