

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

	var t int
	fmt.Fscanf(reader, "%d\n", &t)

	for t > 0 {
		var p, q int
		fmt.Fscanf(reader, "%d %d\n", &p, &q)

		l := int(math.Sqrt(float64(p*p + q*q)))

		isPrime := true

		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				x := i*i + j*j
				if x <= 1 {
					continue
				}
				if x > p*p+q*q {
					continue
				}
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false
					break
				}
			}
			if!isPrime {
				break
			}
		}

		if isPrime {
			fmt.Fprintln(writer, "P")
		} else {
			fmt.Fprintln(writer, "C")
		}

		t--
	}

	writer.Flush()
}

