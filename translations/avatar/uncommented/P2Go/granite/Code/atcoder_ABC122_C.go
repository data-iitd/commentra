
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(nextString(reader))
	q, _ := strconv.Atoi(nextString(reader))
	s := nextString(reader)
	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		problems[i] = make([]int, 2)
		problems[i][0], _ = strconv.Atoi(nextString(reader))
		problems[i][1], _ = strconv.Atoi(nextString(reader))
	}
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = cumsum[i-1] + 1
		if s[i-1:i+1] == "AC" {
			cumsum[i]++
		}
	}
	for _, p := range problems {
		l, r := p[0], p[1]
		fmt.Println(cumsum[r-1]-cumsum[l-1])
	}
}

func nextString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

