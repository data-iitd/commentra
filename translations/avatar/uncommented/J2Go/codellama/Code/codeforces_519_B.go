package main

import (
	"fmt"
	"os"
)

func main() {
	sc := make([]int, 3)
	for i := 0; i < 3; i++ {
		sc[i] = nextInt()
	}
	a := sc[0]
	b := sc[1]
	c := sc[2]
	x := a - b
	y := b - c
	fmt.Println(x)
	fmt.Println(y)
}

func nextInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

