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
	a := []int{}
	for _, s := range strings.Split(strings.TrimSpace(input), " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}
	for e, i := range a {
		if i == 0 {
			fmt.Println(e + 1)
			break
		}
	}
}

