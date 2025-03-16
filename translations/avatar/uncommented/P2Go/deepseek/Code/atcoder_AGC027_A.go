package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	parts := readInts()
	n, x := parts[0], parts[1]
	ints := readInts()
	sort.Ints(ints)
	ans := 0
	if ints[0] > x {
		fmt.Println(0)
		return
	}
	for _, i := range ints {
		if i > x {
			x = 0
			break
		}
		x -= i
		ans += 1
	}
	if x != 0 {
		ans -= 1
	}
	fmt.Println(ans)
}

