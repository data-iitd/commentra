
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	H, _ := fmt.Fscanf(reader, "%d\n", &H)
	W, _ := fmt.Fscanf(reader, "%d\n", &W)
	A, _ := fmt.Fscanf(reader, "%d\n", &A)
	B, _ := fmt.Fscanf(reader, "%d\n", &B)
	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if (i < B && j < A) || (i >= B) && (j >= A) {
				fmt.Print(0)
			} else {
				fmt.Print(1)
			}
		}
		fmt.Println()
	}
}

