
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
	var first bool = true
	for {
		money, err := readInt(r)
		if err!= nil {
			break
		}
		if!first {
			fmt.Fprintln(w)
		}
		first = false
		sum := 0
		num := make([]int, 4)
		for i := 0; i < 4; i++ {
			n, err := readInt(r)
			if err!= nil {
				break
			}
			sum += n * 100 * (i + 1)
			num[i] = n
		}
		change := sum - money
		for i := 3; i >= 0; i-- {
			if change/100/(i+1) > 0 {
				num[i] -= change / 100 / (i + 1)
				change %= 100 * (i + 1)
			}
		}
		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Fprintf(w, "%d %d\n", 100*(i+1), num[i])
			}
		}
	}
	w.Flush()
}

func readInt(r *bufio.Reader) (int, error) {
	raw, err := r.ReadBytes('\n')
	if err!= nil {
		return 0, err
	}
	return strconv.Atoi(strings.TrimSpace(string(raw)))
}

