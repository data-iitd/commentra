
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	var cards []c462b
	var s string
	var left int
	var change int
	var ans int64

	fmt.Scan(&n, &k)
	cards = make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}
	fmt.Scan(&s)
	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++
	}
	for i := 0; i < k; i++ {
		sort.Sort(c462b(cards))
		change = int(math.Min(float64(cards[25].left), float64(k-i)))
		ans += int64(change * change)
		cards[25].left -= change
		i += change - 1
	}
	fmt.Println(ans)
}

type c462b struct {
	left int
}

func (c c462b) Len() int {
	return c.left
}

func (c c462b) Less(i, j int) bool {
	return c[i].left < c[j].left
}

func (c c462b) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}

