package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inputs := readInts(reader)
	q, h, s, d := inputs[0], inputs[1], inputs[2], inputs[3]
	n := inputs[4]

	best1L := min(q*4, h*2, s)
	best2L := min(d, best1L*2)

	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L * (n / 2) + best1L)
	}
}

func readInts(reader *bufio.Reader) []int {
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1] // Remove newline character
	nums := make([]int, 0)
	for _, s := range str {
		nums = append(nums, int(s-'0'))
	}
	return nums
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
	} else {
		if b < c {
			return b
		}
	}
	return c
}

