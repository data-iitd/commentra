package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	vStr := scanner.Text()
	vMap := str2Map(vStr)

	scanner.Scan()
	cStr := scanner.Text()
	cMap := str2Map(cStr)

	max := 0

	for i := 0; i < n; i++ {
		profit := vMap[i] - cMap[i]
		if profit > 0 {
			max += profit
		}
	}

	fmt.Println(max)
}

func str2Map(str string) map[int]int {
	vals := strings.Split(str, " ")
	m := make(map[int]int)

	for i, val := range vals {
		key := i
		num, _ := strconv.Atoi(val)
		m[key] = num
	}

	return m
}

