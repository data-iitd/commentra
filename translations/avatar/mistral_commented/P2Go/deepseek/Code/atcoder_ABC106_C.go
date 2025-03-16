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
	eps = 1.0 / 10000000000
	mod = 1000000007
)

var dd = [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
var ddn = [][]int{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInts() []int {
	line := readLine()
	parts := strings.Split(line, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

func readInt() int {
	nums := readInts()
	return nums[0]
}

func readFloat() float64 {
	nums := readInts()
	return float64(nums[0])
}

func readString() string {
	return readLine()
}

func printString(s string) {
	fmt.Println(s)
}

func main() {
	s := readString()
	k := readInt()

	l := 0
	for _, c := range s {
		if c != '1' {
			if l >= k {
				fmt.Println(1)
				return
			}
			fmt.Println(string(c))
			return
		}
		l++
	}
	fmt.Println(1)
}

