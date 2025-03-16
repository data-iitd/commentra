package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type c462b struct {
	left int
}

func (c *c462b) compareTo(other *c462b) int {
	return c.left - other.left
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	tokens := bufio.NewScanner(bufio.NewReaderString(line))
	tokens.Split(bufio.ScanWords)

	tokens.Scan()
	n, _ := strconv.Atoi(tokens.Text())
	tokens.Scan()
	k, _ := strconv.Atoi(tokens.Text())

	cards := make([]*c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = &c462b{}
	}

	s, _ := reader.ReadString('\n')
	for _, char := range s[:n] {
		cards[char-'A'].left++
	}

	ans := int64(0)
	for i := 0; i < k; i++ {
		sort.Slice(cards, func(a, b int) bool {
			return cards[a].left < cards[b].left
		})

		change := min(cards[25].left, k-i)
		ans += int64(change * change)
		cards[25].left -= change
		i += change - 1
	}

	fmt.Fprintln(writer, ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
