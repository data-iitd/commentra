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
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	c := make(map[int]bool)

	input, _ = reader.ReadString('\n')
	stringsList := strings.Split(strings.TrimSpace(input), " ")

	for _, s := range stringsList {
		indexS := strings.Index(s, "S")
		indexG := strings.Index(s, "G")

		difference := indexS - indexG
		c[difference] = true
	}

	hasNegative := false
	for key := range c {
		if key < 0 {
			hasNegative = true
			break
		}
	}

	if hasNegative {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}
