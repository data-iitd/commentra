package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	scanner.Scan()
	H, _ := fmt.Sscanf(scanner.Text(), "%d", &H)
	scanner.Scan()
	W, _ := fmt.Sscanf(scanner.Text(), "%d", &W)
	scanner.Scan()
	A, _ := fmt.Sscanf(scanner.Text(), "%d", &A)
	scanner.Scan()
	B, _ := fmt.Sscanf(scanner.Text(), "%d", &B)

	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if (i < B && j < A) || (i >= B && j >= A) {
				writer.WriteString("0")
			} else {
				writer.WriteString("1")
			}
		}
		writer.WriteByte('\n')
	}
	writer.Flush()
}

