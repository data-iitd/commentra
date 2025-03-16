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
	ai := []int{}
	bi := []int{}

	for i := 0; i < n; i++ {
		line := readLine(reader)
		parts := strings.Split(line, " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		ai = append(ai, a)
		bi = append(bi, b)
	}

	sort.Ints(ai)
	sort.Ints(bi)

	if n%2 == 1 {
		writer.WriteString(strconv.Itoa(bi[len(bi)/2] - ai[len(ai)/2] + 1) + "\n")
	} else {
		b := float64(ai[len(ai)/2]+ai[len(ai)/2-1]) / 2
		c := float64(bi[len(bi)/2]+bi[len(bi)/2-1]) / 2
		writer.WriteString(strconv.Itoa(int(2*(c-b)+1)) + "\n")
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\n")
	return line
}

