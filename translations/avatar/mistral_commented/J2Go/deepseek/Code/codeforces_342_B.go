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
	inputSlice := strings.Split(strings.TrimSpace(input), " ")
	m, _ := strconv.Atoi(inputSlice[0])
	s, _ := strconv.Atoi(inputSlice[2])
	f, _ := strconv.Atoi(inputSlice[3])
	maxT := -1

	mapThread := make(map[int][]int)

	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mthSlice := strings.Split(strings.TrimSpace(mth), " ")
		k, _ := strconv.Atoi(mthSlice[0])
		mapThread[k] = []int{0, 0}
		mapThread[k][0], _ = strconv.Atoi(mthSlice[1])
		mapThread[k][1], _ = strconv.Atoi(mthSlice[2])
		if k > maxT {
			maxT = k
		}
		m--
	}

	var actions strings.Builder
	direction := 'R'
	if s < f {
		direction = 'R'
	} else {
		direction = 'L'
	}
	distance := 1
	if s > f {
		distance = -1
	}
	current := s

	for t := 1; t <= maxT; t++ {
		if times, ok := mapThread[t]; ok {
			arrival := times[0]
			departure := times[1]

			if (current >= arrival && current <= departure) || (current+distance >= arrival && current+distance <= departure) {
				actions.WriteRune('X')
			} else {
				actions.WriteRune(direction)
				current += distance
			}

			if current == f {
				break
			}
		} else {
			actions.WriteRune(direction)
			current += distance
		}
	}

	for current != f {
		actions.WriteRune(direction)
		current += distance
	}
	fmt.Println(actions.String())
}

