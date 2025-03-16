
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "" {
			break
		}
		cards := strings.Split(line, " ")
		c := make([]int, 3)
		for i, card := range cards {
			c[i], _ = strconv.Atoi(card)
		}
		cardMap := make(map[int]bool)
		for _, card := range c {
			cardMap[card] = true
		}
		sum := c[0] + c[1]
		count := 0
		for i := 1; i <= 10; i++ {
			if!cardMap[i] && sum+i <= 20 {
				count++
			}
		}
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

