
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n int
		f int
		t int
		max int
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for n > 0 {
		fmt.Fscan(reader, &f, &t)
		if max < f+t {
			max = f + t
		}
		n--
	}

	fmt.Println(max)
}

