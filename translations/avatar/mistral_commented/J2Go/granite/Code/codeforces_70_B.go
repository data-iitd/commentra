

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

	s := readLine(reader)

	max := -1
	msgLength := make([]int, 0)
	count := 0
	idx := 0

	for i := 0; i < len(s); i++ {
		c := s[i]

		if c == '.' || c == '?' || c == '!' {
			msgLength = append(msgLength, count+1)
			if count > max {
				max = count
			}
			i++
			count = 0
		} else {
			count++
		}
	}

	if max > n {
		fmt.Println("Impossible")
		return
	}

	ans := 0

	for i := 0; i < len(msgLength); i++ {
		l := msgLength[i]

		for i < len(msgLength)-1 && l+msgLength[i+1]+1 <= n {
			l += msgLength[i+1] + 1
			i++
		}
		ans++
	}

	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!