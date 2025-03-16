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
	var n int
	fmt.Scanf("%d\n", &n)
	var t, h []string
	for i := 0; i < n; i++ {
		t = append(t, make([]byte, 100))
		h = append(h, make([]byte, 100))
		fmt.Scanf("%s\n", &t[i])
		fmt.Scanf("%s\n", &h[i])
	}
	var taro, hanako int
	for i := 0; i < n; i++ {
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		} else if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}
	fmt.Printf("%d %d\n", taro, hanako)
}

