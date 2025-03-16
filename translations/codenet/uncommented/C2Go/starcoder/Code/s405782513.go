package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		c [3]int
		i int
	)
	for {
		_, err := fmt.Scanf("%d %d %d", &c[0], &c[1], &c[2])
		if err!= nil {
			break
		}
		card := make([]int, 10)
		sum := c[0] + c[1]
		count := 0
		for i = 0; i < 3; i++ {
			card[c[i]-1] = 1
		}
		for i = 0; i < 10; i++ {
			if card[i] == 0 && sum+i+1 <= 20 {
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

