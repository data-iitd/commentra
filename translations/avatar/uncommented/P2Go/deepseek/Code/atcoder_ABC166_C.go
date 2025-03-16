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
	inputs := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(inputs[0])
	m, _ := strconv.Atoi(inputs[1])

	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}

	input, _ = reader.ReadString('\n')
	hs := strings.Split(strings.TrimSpace(input), " ")
	h := make([]int, n)
	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(hs[i])
	}

	hp := make(map[int]int)
	for i := 0; i < n; i++ {
		hp[p[i]] = h[i]
	}

	path := make(map[int][]int)
	for i := 0; i < m; i++ {
		input, _ = reader.ReadString('\n')
		ab := strings.Split(strings.TrimSpace(input), " ")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		path[a] = append(path[a], b)
		path[b] = append(path[b], a)
	}

	c := 0
	for i, v := range path {
		f := 0
		for _, j := range v {
			if hp[i] <= hp[j] {
				f = 1
				break
			}
		}
		if f == 0 {
			c++
		}
	}
	fmt.Println(c)
}

