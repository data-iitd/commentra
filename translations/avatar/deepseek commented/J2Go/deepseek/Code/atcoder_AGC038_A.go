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
	H := parseInt(scanner.Text())
	scanner.Scan()
	W := parseInt(scanner.Text())
	scanner.Scan()
	A := parseInt(scanner.Text())
	scanner.Scan()
	B := parseInt(scanner.Text())

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

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

