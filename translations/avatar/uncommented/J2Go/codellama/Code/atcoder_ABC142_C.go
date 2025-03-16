
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	N, _ := strconv.Atoi(scanner.Text())
	idorder := make(map[int]int)
	for i := 1; i <= N; i++ {
		scanner.Scan()
		A, _ := strconv.Atoi(scanner.Text())
		idorder[A] = i
	}
	for i := 1; i <= N; i++ {
		fmt.Printf("%d ", idorder[i])
	}
}

