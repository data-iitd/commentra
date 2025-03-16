package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	var H, W, A, B int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d %d %d %d", &H, &W, &A, &B)
	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if (i < B && j < A) || (i >= B && j >= A) {
				bw.WriteString("0")
			} else {
				bw.WriteString("1")
			}
		}
		bw.WriteString("\n")
	}
	bw.Flush()
}

