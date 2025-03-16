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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var H, W, A, B int
	fmt.Fscan(reader, &H, &W, &A, &B)

	if W < 2*A || H < 2*B {
		fmt.Fprintln(writer, -1)
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B && j < A || i >= B && j >= A {
				fmt.Fprint(writer, "0")
			} else {
				fmt.Fprint(writer, "1")
			}
		}
		fmt.Fprintln(writer)
	}
}

