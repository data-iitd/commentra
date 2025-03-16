
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Card struct {
	left int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of test cases:")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	fmt.Println("Enter the number of cards:")
	k, _ := strconv.Atoi(reader.ReadLine()[0:1])
	fmt.Println("Enter the cards:")
	cards := make([]Card, 26)
	for i := 0; i < 26; i++ {
		cards[i] = Card{}
	}
	s, _ := reader.ReadString('\n')
	for t := 0; t < n; t++ {
		cards[s[t]-'A'].left++
	}
	var ans int64
	for i := 0; i < k; i++ {
		sortCards(cards)
		change := int64(min(cards[25].left, k-i))
		ans += change * change
		cards[25].left -= int(change)
		i += int(change) - 1
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sortCards(cards []Card) {
	for i := 0; i < len(cards)-1; i++ {
		for j := 0; j < len(cards)-i-1; j++ {
			if cards[j].left < cards[j+1].left {
				cards[j], cards[j+1] = cards[j+1], cards[j]
			}
		}
	}
}

// END-OF-CODE