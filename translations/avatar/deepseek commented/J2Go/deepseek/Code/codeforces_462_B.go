package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type c462b struct {
	left int
}

func (c c462b) CompareTo(o c462b) int {
	return c.left - o.left
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	n, _ := strconv.Atoi(tokens[0])
	k, _ := strconv.Atoi(tokens[1])

	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}

	line, _ = reader.ReadString('\n')
	for t := 0; t < n; t++ {
		cards[line[t]-'A'].left++
	}

	var ans int64 = 0
	for i := 0; i < k; i++ {
		for j := 0; j < 25; j++ {
			if cards[j].CompareTo(cards[25]) > 0 {
				cards[j], cards[25] = cards[25], cards[j]
			}
		}
		change := int64(min(cards[25].left, k-i))
		ans += change * change
		cards[25].left -= int(change)
		i += int(change) - 1
	}

	fmt.Fprintln(writer, ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
