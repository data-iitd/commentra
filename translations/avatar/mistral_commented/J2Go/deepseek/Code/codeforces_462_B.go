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
	parts := strings.Fields(input)
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}

	input, _ = reader.ReadString('\n')
	for i := 0; i < n; i++ {
		cards[input[i]-'A'].left++
	}

	var ans int64 = 0
	for i := 0; i < k; i++ {
		sort.Slice(cards, func(i, j int) bool {
			return cards[i].left > cards[j].left
		})
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

