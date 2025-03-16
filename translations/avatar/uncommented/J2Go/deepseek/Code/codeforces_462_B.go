package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	st := strings.Split(input, " ")
	n, _ := strconv.Atoi(st[0])
	k, _ := strconv.Atoi(st[1])

	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}

	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++
	}

	var ans int64 = 0
	for i := 0; i < k; i++ {
		sort.Slice(cards, func(i, j int) bool {
			return cards[i].left < cards[j].left
		})
		change := int64(0)
		if cards[25].left > 0 {
			change = int64(min(cards[25].left, k-i))
		}
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

