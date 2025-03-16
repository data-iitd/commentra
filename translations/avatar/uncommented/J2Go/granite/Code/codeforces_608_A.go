
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, s int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &s)
	max := 0
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &f, &t)
		if max < f+t {
			max = f + t
		}
	}
	fmt.Println(int(math.Max(float64(max), float64(s))))
}

