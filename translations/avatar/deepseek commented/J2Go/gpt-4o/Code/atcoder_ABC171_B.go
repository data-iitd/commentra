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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}

func solve(reader *bufio.Reader, writer *bufio.Writer) {
	n, _ := strconv.Atoi(readLine(reader))
	k, _ := strconv.Atoi(readLine(reader))
	a := make([]int, n)

	line := readLine(reader)
	tokens := strings.Split(line, " ")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(tokens[i])
	}

	sort.Ints(a) // Sorts the array
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i] // Sums the first k elements
	}
	fmt.Fprintln(writer, ans) // Prints the result
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// <END-OF-CODE>
