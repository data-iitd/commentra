package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var S string
	S, _ = reader.ReadString('\n')
	S = strings.TrimSpace(S)
	score := 0
	for i := 0; i < len(S); i++ {
		my := 'g'
		if i%2 == 1 {
			my = 'p'
		}
		his := S[i]
		if my!= his {
			score += my == 'p'
		}
	}
	fmt.Println(score)
}

