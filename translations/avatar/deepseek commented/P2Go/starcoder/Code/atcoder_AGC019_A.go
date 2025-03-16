package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the values of q, h, s, d and n")
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	q, h, s, d, n := parseLine(line)
	best1L := min(q*4, h*2, s)
	best2L := min(d, best1L*2)
	if n%2 == 0 {
		fmt.Println(best2L*(n/2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}

func parseLine(line string) (int, int, int, int, int) {
	parts := strings.Split(line, " ")
	q, _ := strconv.Atoi(parts[0])
	h, _ := strconv.Atoi(parts[1])
	s, _ := strconv.Atoi(parts[2])
	d, _ := strconv.Atoi(parts[3])
	n, _ := strconv.Atoi(parts[4])
	return q, h, s, d, n
}

// 