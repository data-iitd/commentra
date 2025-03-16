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

func main() {
	f := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	st := strings.Split(strings.TrimSpace(f.ReadString()), " ")
	n, _ := strconv.Atoi(st[0])
	k, _ := strconv.Atoi(st[1])

	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}

	s := strings.TrimSpace(f.ReadString())
	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++
	}

	ans := 0
	for i := 0; i < k; i++ {
		sort.Slice(cards, func(i, j int) bool {
			return cards[i].left < cards[j].left
		})
		change := int(math.Min(float64(cards[25].left), float64(k-i)))
		ans += change * change
		cards[25].left -= change
		i += change - 1
	}

	fmt.Println(ans)
}

