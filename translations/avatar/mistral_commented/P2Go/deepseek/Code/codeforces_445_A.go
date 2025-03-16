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
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	var l [][]string

	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		row := strings.Split(strings.TrimSpace(line), "")

		for j := 0; j < m; j++ {
			if row[j] == "." {
				if (i+j)%2 != 0 {
					row[j] = "W"
				} else {
					row[j] = "B"
				}
			}
		}

		l = append(l, row)
	}

	for _, row := range l {
		fmt.Println(strings.Join(row, ""))
	}
}

