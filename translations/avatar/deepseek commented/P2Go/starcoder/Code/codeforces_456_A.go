
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}
	sort.Slice(m, func(i, j int) bool {
		return m[i][1] > m[j][1]
	})
	a := m[0]
	for _, i := range m[1:] {
		if i[1] > a[1] {
			fmt.Println("Happy Alex")
			break
		}
		a = i
	} else {
		fmt.Println("Poor Alex")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

