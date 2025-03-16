package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func solve(S string, T string, A int, B int, U string) {
	if S == U {
		A--
	}
	if T == U {
		B--
	}
	fmt.Println(A, B)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	S := scanner.Text()
	scanner.Scan()
	T := scanner.Text()
	scanner.Scan()
	A := parseInt(scanner.Text())
	scanner.Scan()
	B := parseInt(scanner.Text())
	scanner.Scan()
	U := scanner.Text()
	solve(S, T, A, B, U)
}

func parseInt(s string) int {
	var i int
	fmt.Sscanf(s, "%d", &i)
	return i
}
