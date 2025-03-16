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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fast := Fast{}
	fast.sol(reader, writer)
}

type Fast struct{}

func (f Fast) sol(reader *bufio.Reader, writer *bufio.Writer) {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	cum := make([]int, len(line)+1)
	cum[0] = cum[len(line)] = 0
	for i := 1; i < len(line); i++ {
		if line[i] == line[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	qStr, _ := reader.ReadString('\n')
	qStr = strings.TrimSpace(qStr)
	q, _ := strconv.Atoi(qStr)

	for i := 0; i < q; i++ {
		query, _ := reader.ReadString('\n')
		query = strings.TrimSpace(query)
		parts := strings.Split(query, " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		writer.WriteString(fmt.Sprintf("%d\n", cum[r-1]-cum[l-1]))
	}
}

