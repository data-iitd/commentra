

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
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	inputSlice := strings.Split(input, ",")
	m, _ := strconv.Atoi(inputSlice[0])
	s, _ := strconv.Atoi(inputSlice[1])
	f, _ := strconv.Atoi(inputSlice[2])
	maxT := -1
	map := make(map[int][]int)
	for m > 0 {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		input = strings.Replace(input, "\n", "", -1)
		input = strings.Replace(input, " ", "", -1)
		inputSlice := strings.Split(input, ",")
		k, _ := strconv.Atoi(inputSlice[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(inputSlice[1])
		map[k][1], _ = strconv.Atoi(inputSlice[2])
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}
	actions := strings.Builder{}
	M := 'R'
	if s > f {
		M = 'L'
	}
	d := 1
	if s > f {
		d = -1
	}
	cur := s
	a := -1
	b := -1
	for t := 1; t <= maxT; t++ {
		if _, ok := map[t]; ok {
			a = map[t][0]
			b = map[t][1]
			if (cur >= a && cur <= b) || (cur+d >= a && cur+d <= b) {
				actions.WriteString("X")
			} else {
				actions.WriteString(string(M))
				cur += d
			}
			if cur == f {
				break
			}
		} else {
			actions.WriteString(string(M))
			cur += d
		}
	}
	for cur!= f {
		actions.WriteString(string(M))
		cur += d
	}
	fmt.Println(actions.String())
}

Translate the above Go code to C++ and end with comment "