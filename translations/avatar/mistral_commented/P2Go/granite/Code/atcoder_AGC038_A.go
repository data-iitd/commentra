
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	H, _ := strconv.Atoi(nextString(reader))
	W, _ := strconv.Atoi(nextString(reader))
	A, _ := strconv.Atoi(nextString(reader))
	B, _ := strconv.Atoi(nextString(reader))

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B {
				if j < A {
					fmt.Print("0")
				} else {
					fmt.Print("1")
				}
			} else {
				if j < A {
					fmt.Print("1")
				} else {
					fmt.Print("0")
				}
			}
		}
		fmt.Println()
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

