package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Card struct {
	left int
}

type ByLeft []Card

func (a ByLeft) Len() int           { return len(a) }
func (a ByLeft) Less(i, j int) bool { return a[i].left < a[j].left }
func (a ByLeft) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	var n, k int
	fmt.Sscanf(line, "%d %d", &n, &k)

	cards := make([]Card, 26)
	line, _ = reader.ReadString('\n')
	s := line[:len(line)-1] // Remove newline character

	for _, char := range s {
		cards[char-'A'].left++
	}

	var ans int64 = 0
	for i := 0; i < k; i++ {
		sort.Sort(ByLeft(cards))
		change := min(cards[25].left, k-i)
		ans += int64(change * change)
		cards[25].left -= change
		i += change - 1
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
