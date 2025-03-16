
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

	var n, k int
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fscanf(reader, "%d\n", &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
			}
		}
	}

	sum := 0
	for i := 0; i < k; i++ {
		sum += a[i]
	}

	fmt.Fprintf(writer, "%d\n", sum)
	writer.Flush()
}

