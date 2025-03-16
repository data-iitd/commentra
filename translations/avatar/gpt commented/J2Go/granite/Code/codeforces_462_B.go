
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

func (c *Card) Len() int {
	return c.left
}

func (c *Card) Less(other *Card) bool {
	return c.left < other.left
}

func (c *Card) Swap(i, j int) {
	c.left, other.left = other.left, c.left
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	line, _ := in.ReadString('\n')
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	cards := make([]Card, 26)
	for i := 0; i < 26; i++ {
		cards[i] = Card{}
	}

	line, _ = in.ReadString('\n')
	for _, c := range line {
		cards[c-'A'].left++
	}

	sort.Sort(&cards)

	ans := 0
	for i := 0; i < k; i++ {
		change := cards[25].left
		if change > k-i {
			change = k - i
		}
		ans += change * change
		cards[25].left -= change
		i += change - 1
	}

	fmt.Fprintf(out, "%d\n", ans)
}

// Translate the above Go code to C++ and end with comment "