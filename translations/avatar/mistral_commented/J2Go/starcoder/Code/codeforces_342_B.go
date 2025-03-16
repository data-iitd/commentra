
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
	m, _ := strconv.Atoi(input[0])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])
	maxT := -1

	map := make(map[int][]int)

	for m > 0 {
		input, _ := reader.ReadString('\n')
		input = strings.Split(input, " ")
		k, _ := strconv.Atoi(input[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(input[1])
		map[k][1], _ = strconv.Atoi(input[2])
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}

	actions := ""
	M := 'R'
	if s < f {
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

			if _, ok := map[t]; ok && (cur >= a && cur <= b || cur+d >= a && cur+d <= b) {
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

	for cur!= f {
		actions += string(M)
		cur += d
	}
	fmt.Println(actions)
}

