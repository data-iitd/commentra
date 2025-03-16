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
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	k, _ := strconv.Atoi(s)
	l := 0
	for _, c := range s {
		if c!= '1' {
			break
		}
		l++
	}
	if l >= k {
		fmt.Println(1)
	} else {
		fmt.Println(string(s[l]))
	}
}

