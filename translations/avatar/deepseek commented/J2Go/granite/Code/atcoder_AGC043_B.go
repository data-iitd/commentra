

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

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(s[i]) - int(s[i-1])))
	}

	if n == 2 {
		fmt.Fprintln(writer, sb.String()[0])
		writer.Flush()
		return
	}

	s = sb.String()
	if strings.Contains(s, "1") {
		ans := cal(s, '1')
		fmt.Fprintln(writer, ans)
	} else {
		ans := cal(s, '2') * 2
		fmt.Fprintln(writer, ans)
	}

	writer.Flush()
}

func cal(s string, c byte) int {
	n := len(s)
	m := n - 1
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == c && (m&i) == i {
			ans ^= 1
		}
	}
	return ans
}

// 