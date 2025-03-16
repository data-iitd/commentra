
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

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &l[i])
	}

	l2 := make([]int, n)
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}

	mx := 0
	for i := 0; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
		}
	}

	for i := 0; i < n; i++ {
		if l2[i] == mx {
			fmt.Println(i + 1)
			break
		}
	}
}
