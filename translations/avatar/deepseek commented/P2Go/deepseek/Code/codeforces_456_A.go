package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Pair struct {
	first, second int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	m := make([]Pair, n)

	for i := 0; i < n; i++ {
		line := readLine(reader)
		parts := strings.Split(line, " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		m[i] = Pair{a, b}
	}

	sort.Slice(m, func(i, j int) bool {
		return m[i].second > m[j].second
	})

	a := m[0]
	for _, i := range m[1:] {
		if i.second > a.second {
			fmt.Println("Happy Alex")
			return
		}
		a = i
	}
	fmt.Println("Poor Alex")
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\n")
	return line
}
