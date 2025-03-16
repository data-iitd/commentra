
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
	inputArray := strings.Split(input, " ")
	m, _ := strconv.Atoi(inputArray[0])
	s, _ := strconv.Atoi(inputArray[2])
	f, _ := strconv.Atoi(inputArray[3])
	maxT := -1
	map := make(map[int][]int)

	for m > 0 {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		inputArray := strings.Split(input, " ")
		k, _ := strconv.Atoi(inputArray[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(inputArray[1])
		map[k][1], _ = strconv.Atoi(inputArray[2])
		maxT = max(maxT, k)
		m--
	}

	actions := ""
	var M byte
	if s < f {
		M = 'R'
	} else {
		M = 'L'
	}
	d := 1
	if s < f {
		d = 1
	} else {
		d = -1
	}
	cur := s
	a := -1
	b := -1

	for t := 1; t <= maxT; t++ {
		if map[t] != nil {
			a = map[t][0]
			b = map[t][1]

			if map[t] != nil && (cur >= a && cur <= b || cur+d >= a && cur+d <= b) {
				actions += "X"
			} else {
				actions += string(M)
				cur += d
			}

			if cur == f {
				break
			}
		} else {
			actions += string(M)
			cur += d
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

