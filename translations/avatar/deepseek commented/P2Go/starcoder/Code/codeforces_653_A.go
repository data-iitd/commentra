
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
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}
	sort.Ints(l)
	for i := 0; i < n; i++ {
		if l[i]+1 < n && l[i]+2 < n {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

