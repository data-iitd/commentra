
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	H := nextInt(sc)
	W := nextInt(sc)
	A := nextInt(sc)
	B := nextInt(sc)

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

// END-OF-CODE