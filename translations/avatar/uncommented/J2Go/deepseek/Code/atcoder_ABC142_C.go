package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)
	idorder := make(map[int]int)
	for i := 1; i <= N; i++ {
		scanner.Scan()
		var A int
		fmt.Sscan(scanner.Text(), &A)
		idorder[A] = i
	}
	for i := 1; i <= N; i++ {
		fmt.Printf("%d ", idorder[i])
	}
	fmt.Println()
}

