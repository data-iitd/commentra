package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var T, S, q int
	var previous int64
	var answer int
	fmt.Scanf("%d %d %d", &T, &S, &q)
	previous = int64(S)
	for previous < int64(T) {
		answer++
		previous *= int64(q)
	}
	fmt.Println(answer)
}

