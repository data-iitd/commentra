package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 32768)
	input := func() string {
		bytes, err := reader.ReadBytes('\n')
		if err != nil {
			panic(err)
		}
		return string(bytes[:len(bytes)-1])
	}

	a, _ := strconv.Atoi(input())
	b, _ := strconv.Atoi(input())
	c, _ := strconv.Atoi(input())
	d, _ := strconv.Atoi(input())

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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

