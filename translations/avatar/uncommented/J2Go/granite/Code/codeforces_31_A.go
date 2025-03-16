
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	}
	k, j, i := 0, 0, 0
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i!= j && t == (a[i]+a[j]) {
					fmt.Println(k + 1, i + 1, j + 1)
					return
				}
			}
		}
	}
	fmt.Println(-1)
}

