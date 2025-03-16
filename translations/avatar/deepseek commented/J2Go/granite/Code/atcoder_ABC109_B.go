
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

	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	past := make(map[int]string)
	next := ""
	ans := true

	for i := 0; i < N; i++ {
		s := readLine(reader)

		if _, ok := past[i]; ok {
			ans = false
			break
		}
		past[i] = s

		if i!= 0 {
			if string(s[0])!= next {
				ans = false
				break
			}
		}
		next = string(s[len(s)-1])
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

