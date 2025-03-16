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

	n, _ := strconv.Atoi(readLine(reader))
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	max := -1
	var msgLength []int
	count := 0
	idx := 0

	for i := 0; i < len(input); i++ {
		c := input[i]

		if c == '.' || c == '?' || c == '!' {
			msgLength = append(msgLength, count+1)
			if count+1 > max {
				max = count + 1
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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

