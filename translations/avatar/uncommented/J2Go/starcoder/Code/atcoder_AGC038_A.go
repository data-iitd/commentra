package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	defer bw.Flush()

	H, W, A, B := 0, 0, 0, 0
	sc.Scan()
	H, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	W, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	A, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	B, _ = strconv.Atoi(sc.Text())

	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B && j < A || i >= B && j >= A {
				bw.WriteByte('0')
			} else {
				bw.WriteByte('1')
			}
		}
		bw.WriteByte('\n')
	}
}

