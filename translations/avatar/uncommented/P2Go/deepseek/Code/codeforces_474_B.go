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
	L := []string{}
	r := 1
	for _, k := range strings.Split(input, " ") {
		for i := 0; i < mustParseInt(k); i++ {
			L = append(L, strconv.Itoa(r))
		}
		r++
	}
	input, _ = reader.ReadString('\n')
	for _, j := range strings.Split(input, " ") {
		fmt.Println(L[mustParseInt(j)-1])
	}
}

func mustParseInt(s string) int {
	i, err := strconv.Atoi(strings.TrimSpace(s))
	if err != nil {
		panic(err)
	}
	return i
}

