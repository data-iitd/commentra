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
	inputs := strings.Split(input, " ")
	m, _ := strconv.Atoi(inputs[1])
	s, _ := strconv.Atoi(inputs[2])
	f, _ := strconv.Atoi(inputs[3])
	maxT := -1
	mapa := make(map[int][]int)
	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mth = strings.TrimSpace(mth)
		mths := strings.Split(mth, " ")
		k, _ := strconv.Atoi(mths[0])
		mapa[k] = []int{0, 0}
		mapa[k][0], _ = strconv.Atoi(mths[1])
		mapa[k][1], _ = strconv.Atoi(mths[2])
		if k > maxT {
			maxT = k
		}
		m--
	}
	var actions strings.Builder
	d := 1
	if s < f {
		d = 1
	} else {
		d = -1
	}
	cur := s
	for t := 1; t <= maxT; t++ {
		if val, ok := mapa[t]; ok {
			a, b := val[0], val[1]
			if (cur >= a && cur <= b) || (cur+d >= a && cur+d <= b) {
				actions.WriteString("X")
			} else {
				actions.WriteString(string('R'))
				cur += d
			}
		} else {
			if s < f {
				actions.WriteString("R")
				cur += d
			} else {
				actions.WriteString("L")
				cur += d
			}
		}
		if cur == f {
			break
		}
	}
	for cur != f {
		if s < f {
			actions.WriteString("R")
			cur += d
		} else {
			actions.WriteString("L")
			cur += d
		}
	}
	fmt.Println(actions.String())
}
