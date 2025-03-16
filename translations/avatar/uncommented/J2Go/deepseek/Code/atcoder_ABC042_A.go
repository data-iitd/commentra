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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	x, _ := strconv.Atoi(parts[0])
	a, _ := strconv.Atoi(parts[1])
	y, _ := strconv.Atoi(parts[2])
	h := "NO"
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		if x+y+a == 17 {
			h = "YES"
		}
	}
	fmt.Println(h)
}

