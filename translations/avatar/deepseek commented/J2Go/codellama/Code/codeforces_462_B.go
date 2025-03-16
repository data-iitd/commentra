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
	var s string
	fmt.Scan(&n, &k)
	fmt.Scan(&s)
	cards := make([]c462b, 26)
	for i := 0; i < 26; i++ {
		cards[i] = c462b{}
	}
	for i := 0; i < n; i++ {
		cards[s[i]-'A'].left++
	}
	ans := 0
	for i := 0; i < k; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(cards)))
		change := min(cards[25].left, k-i)
		ans += change * change
		cards[25].left -= change
		i += change - 1
	}
	fmt.Println(ans)
}

type c462b struct {
	left int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

