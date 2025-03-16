package main

import (
	 bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var H, W, A, B int
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", &H, &W, &A, &B)

	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	writer := bufio.NewWriter(os.Stdout)
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if (i < B && j < A) || (i >= B && j >= A) {
				writer.WriteString("0")
			} else {
				writer.WriteString("1")
			}
		}
		writer.WriteString("\n")
	}
	writer.Flush()
}
