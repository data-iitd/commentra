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
	parts := strings.Fields(input)
	m, _ := strconv.Atoi(parts[1])
	s, _ := strconv.Atoi(parts[2])
	f, _ := strconv.Atoi(parts[3])
	maxT := -1
	mapData := make(map[int][]int)

	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mthParts := strings.Fields(mth)
		k, _ := strconv.Atoi(mthParts[0])
		a, _ := strconv.Atoi(mthParts[1])
		b, _ := strconv.Atoi(mthParts[2])
		mapData[k] = []int{a, b}
		if k > maxT {
			maxT = k
		}
		m--
	}

	var actions strings.Builder
	var M rune
	if s < f {
		M = 'R'
	} else {
		M = 'L'
	}
	d := 1
	if s > f {
		d = -1
	}
	cur := s
	a, b := -1, -1

	for t := 1; t <= maxT; t++ {
		if val, exists := mapData[t]; exists {
			a = val[0]
			b = val[1]
		}
		if exists && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteRune('X')
		} else {
			actions.WriteRune(M)
			cur += d
		}
		if cur == f {
			break
		}
	}

	for cur != f {
		actions.WriteRune(M)
		cur += d
	}

	fmt.Println(actions.String())
}

// <END-OF-CODE>
