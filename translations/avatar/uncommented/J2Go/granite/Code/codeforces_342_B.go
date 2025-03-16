
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
	input := strings.Split(readLine(reader), " ")
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])
	maxT := -1
	map_ := make(map[int][]int)
	for m > 0 {
		input := strings.Split(readLine(reader), " ")
		k, _ := strconv.Atoi(input[0])
		map_[k] = []int{
			strconv.Atoi(input[1]),
			strconv.Atoi(input[2]),
		}
		maxT = max(maxT, k)
		m--
	}
	actions := &strings.Builder{}
	d := 1
	if s > f {
		d = -1
	}
	cur := s
	a, b := -1, -1
	for t := 1; t <= maxT; t++ {
		if v, ok := map_[t]; ok {
			a, b = v[0], v[1]
		}
		if (cur >= a && cur <= b) || (cur+d >= a && cur+d <= b) {
			actions.WriteString("X")
		} else {
			actions.WriteString(string(byte('L'+d)))
			cur += d
		}
		if cur == f {
			break
		}
	}
	for cur!= f {
		actions.WriteString(string(byte('L' + d)))
		cur += d
	}
	fmt.Println(actions.String())
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

