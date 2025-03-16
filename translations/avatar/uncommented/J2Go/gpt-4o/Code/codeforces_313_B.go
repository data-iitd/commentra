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

	f := Fast{}
	f.sol(reader, writer)
}

type Fast struct{}

func (f *Fast) sol(reader *bufio.Reader, writer *bufio.Writer) {
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	cum := make([]int, len(s)+1)
	cum[0] = 0
	cum[len(s)] = 0

	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	qStr, _ := reader.ReadString('\n')
	q, _ := strconv.Atoi(strings.TrimSpace(qStr))

	for i := 0; i < q; i++ {
		queryStr, _ := reader.ReadString('\n')
		query := strings.Fields(queryStr)
		l, _ := strconv.Atoi(query[0])
		r, _ := strconv.Atoi(query[1])
		writer.WriteString(fmt.Sprintf("%d\n", cum[r-1]-cum[l-1]))
	}
}

// <END-OF-CODE>
