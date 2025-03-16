
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	a := make([]int, n)
	r := 0
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		r ^= a[i]
	}
	for i := 0; i < n; i++ {
		if i!= 0 {
			fmt.Print(" ")
		}
		fmt.Print(r ^ a[i])
	}
	fmt.Println()
}

