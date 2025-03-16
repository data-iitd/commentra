package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	num := 998244353
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, _ := strconv.Atoi(readLine(reader))
	ai := make([]int, n)
	bi := make([]int, n)

	for i := 0; i < n; i++ {
		line := readLine(reader)
		parts := strings.Split(line, " ")
		ai[i], _ = strconv.Atoi(parts[0])
		bi[i], _ = strconv.Atoi(parts[1])
	}

	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 {
		writer.WriteString(fmt.Sprintf("%d\n", bi[n/2]-ai[n/2]+1))
	} else {
		b := float64(ai[n/2]+ai[n/2-1]) / 2
		c := float64(bi[n/2]+bi[n/2-1]) / 2
		writer.WriteString(fmt.Sprintf("%d\n", int(2*(c-b)+1)))
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

