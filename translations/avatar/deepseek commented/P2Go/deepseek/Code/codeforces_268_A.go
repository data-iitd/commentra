package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	n = strings.TrimSpace(n)
	nInt, _ := strconv.Atoi(n)

	q := []string{}
	count := 0

	for i := 0; i < nInt; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		parts := strings.Split(input, " ")
		q = append(q, parts...)
	}

	for j := 0; j < len(q); j++ {
		for k := 0; k < len(q); k++ {
			if j == k {
				continue
			}
			if q[j][0] == q[k][len(q[k])-1] {
				count++
			}
		}
	}

	fmt.Println(count)
}

