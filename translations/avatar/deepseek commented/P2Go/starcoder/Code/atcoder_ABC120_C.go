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
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.Replace(s, "\n", "", -1)
	a := make(map[rune]int)
	for _, v := range s {
		a[v]++
	}
	ans := 0
	for _, v := range a {
		ans += v
	}
	fmt.Println(ans * 2)
}

