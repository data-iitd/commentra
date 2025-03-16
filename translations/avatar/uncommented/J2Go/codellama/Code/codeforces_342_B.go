
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	inputSlice := strings.Split(input, " ")
	m, _ := strconv.Atoi(inputSlice[1])
	s, _ := strconv.Atoi(inputSlice[2])
	f, _ := strconv.Atoi(inputSlice[3])
	maxT := -1
	map := make(map[int][]int)
	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mth = strings.TrimSpace(mth)
		mthSlice := strings.Split(mth, " ")
		k, _ := strconv.Atoi(mthSlice[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(mthSlice[1])
		map[k][1], _ = strconv.Atoi(mthSlice[2])
		maxT = max(maxT, k)
		m--
	}
	actions := ""
	var M byte
	var d int
	if s < f {
		M = 'R'
		d = 1
	} else {
		M = 'L'
		d = -1
	}
	cur := s
	a := -1
	b := -1
	for t := 1; t <= maxT; t++ {
		if map[t] != nil {
			a = map[t][0]
			b = map[t][1]
		}
		if map[t] != nil && (cur >= a && cur <= b || cur+d >= a && cur+d <= b) {
			actions += "X"
		} else {
			actions += string(M)
			cur += d
		}
		if cur == f {
			break
		}
	}
	for cur != f {
		actions += string(M)
		cur += d
	}
	fmt.Println(actions)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 