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

	input := readLine(reader)
	parts := strings.Split(input, " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	a := make([]int, n)
	input, _ = readLine(reader)
	numbers := strings.Split(input, " ")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(numbers[i])
	}

	sort.Ints(a)
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	fmt.Fprintln(writer, ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	return line
}
