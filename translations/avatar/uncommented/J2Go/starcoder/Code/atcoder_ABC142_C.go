package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	N, _ := strconv.Atoi(scanner.Text())
	idorder := make(map[int]int)
	for i := 1; i <= N; i++ {
		A, _ := strconv.Atoi(scanner.Text())
		idorder[A] = i
	}
	for i := 1; i <= N; i++ {
		fmt.Print(idorder[i])
		fmt.Print(" ")
	}
}

