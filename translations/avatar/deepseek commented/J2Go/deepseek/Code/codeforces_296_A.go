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

	n, _ := strconv.Atoi(readLine(reader))
	array := make([]int, 1001)

	for i := 0; i < n; i++ {
		index, _ := strconv.Atoi(readLine(reader))
		array[index]++
	}

	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}

	if n%2 == 0 {
		if countMax <= n/2 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	} else {
		if countMax <= n/2+1 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}
