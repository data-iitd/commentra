package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func readInput() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var result []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		result = append(result, num)
	}
	return result
}

func main() {
	inputs := readInput()
	n := inputs[0]
	m := inputs[1]
	lst := inputs[2:]
	l := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := l[lst[i]]; !ok {
			l[lst[i]] = 1
		} else {
			l[lst[i]] += 1
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			res += n - i - l[lst[i]]
			l[lst[i]] -= 1
		} else {
			res += n - i - 1
		}
	}
	fmt.Println(res)
}

