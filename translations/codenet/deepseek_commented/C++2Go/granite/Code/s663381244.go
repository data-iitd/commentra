
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	var money int
	for {
		fmt.Fscanf(r, "%d\n", &money)
		if money == 0 {
			break
		}
		m := []int{10, 50, 100, 500}
		var sum int
		num := make([]int, 4)
		for i := 0; i < 4; i++ {
			fmt.Fscanf(r, "%d", &num[i])
			sum += num[i] * m[i]
		}
		change := sum - money
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 {
				num[i] = num[i] - change/m[i]
				change = change % m[i]
			}
		}
		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Fprintf(w, "%d %d\n", m[i], num[i])
			}
		}
	}
	w.Flush()
}

