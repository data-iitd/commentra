package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n := input[:len(input)-1]
	s := strings.Split(n, " ")
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}
	s = reverse(s)
	c, a := -1, ""
	for k := range w {
		if w[k] == maxValue(w) {
			if indexOf(k, s) > c {
				a = k
				c = indexOf(k, s)
			}
		}
	}
	fmt.Println(a)
}

func reverse(s []string) []string {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func maxValue(m map[string]int) int {
	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	return max
}

func indexOf(element string, data []string) int {
	for k, v := range data {
		if element == v {
			return k
		}
	}
	return -1
}
