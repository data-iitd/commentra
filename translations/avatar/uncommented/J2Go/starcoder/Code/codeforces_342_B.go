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
	input = strings.Split(input, " ")
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])
	maxT := -1
	map := make(map[int][]int)
	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mth = strings.Split(mth, " ")
		k, _ := strconv.Atoi(mth[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(mth[1])
		map[k][1], _ = strconv.Atoi(mth[2])
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}
	actions := new(strings.Builder)
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
		if _, ok := map[t]; ok {
			a = map[t][0]
			b = map[t][1]
		}
		if _, ok := map[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteString("X")
		} else {
			actions.WriteString(string(M))
			cur += d
		}
		if cur == f {
			break
		}
	}
	for cur!= f {
		actions.WriteString(string(M))
		cur += d
	}
	fmt.Println(actions)
}

