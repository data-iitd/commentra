package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Card struct {
	left int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	var s string
	var cards [26]Card
	var ans int64

	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	s = strings.TrimSpace(reader.ReadString())
	for i := 0; i < n; i++ {
		cards[s[i]-'A'].left++
	}

	sort.Slice(cards[:], func(i, j int) bool {
		return cards[i].left < cards[j].left
	})

	for i := 0; i < k; i++ {
		change := int64(min(cards[25].left, k-i))
		ans += change * change
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

